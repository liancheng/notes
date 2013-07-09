.. meta::
    :tags: puppet, vm

############################
The Learning Puppet tutorial
############################

Tutorial link: http://docs.puppetlabs.com/learning/

Download the CentOS VM: http://info.puppetlabs.com/download-learning-puppet-VM.html

.. note::

    For VirtualBox users, change the network type to "bridged" before running the VM.

Root password: puppet

Chapter 1. Resources and RAL
============================

First command to run::

    $ puppet resource service

This command queries all service resources.  The ``resource`` subcommand is used to inspect and modify resources, while ``service`` is a *resource type*.

Abstraction
-----------

Puppet's resource abstraction layer (RAL):

*   *Similar resources can be grouped into types*. Services will tend to look like services, and users will tend to look like users.
*   *The description of a resource type can be separated from its implementation*. You can talk about whether a service is started without needing to know how to start it.
*   With a good enough description of a resource type, *it’s possible to declare a desired state for a resource* — instead of saying “run this command that starts a service,” say “ensure this service is running.”

The RAL consists of **types** (high-level models) and **providers** (platform-specific implementations) — by splitting the two, it lets you describe desired resource states in a way that isn’t tied to a specific OS.

The ``resource`` subcommand
---------------------------

The general form::

    $ puppet resource <TYPE> <NAME> <ATTRIBUTE>=<VALUE> ...

Documentations of different resource types can be found in `the type reference`__, or use the ``describe`` subcommand::

    $ puppet describe -l            # List all of the resource types avaialble on the system
    $ puppet describe -s <TYPE>     # Print short information about a type, without describing every attribute
    $ puppet describe <TYPE>        # Print long information, similar to what appears in the type reference

__ http://docs.puppetlabs.com/references/latest/type.html

Chapter 2. Manifests
====================

Puppet programs are called “manifests,” and they use the .pp file extension.

The ``apply`` subcommand
------------------------

General form::

    $ puppet apply <MANIFEST-FILE>

Master/agent
------------

The puppet master always reads one special manifest, called the “site manifest” or site.pp. It uses this to compile a catalog, which it sends back to the agent. 

On the VM, the site manifest is at ``/etc/puppetlabs/puppet/manifests/site.pp``.

Run ``puppet agent --test`` will trigger puppet agent to run in the foreground one so that you can see what it's doing in real time.

.. topic:: Exercise: SSH Aurthorized Key

    Answer::

        ssh_authorized_key { '/root/.ssh/authorized_keys':
          ensure => present,
          name   => 'root',
          type   => 'ssh-rsa',
          user   => 'root',
          key    => 'AAAAB3NzaC1yc2EA...',
        }

Chapter 3. Resource Ordering
============================

http://docs.puppetlabs.com/puppet/latest/reference/lang_relationships.html

Resources can be ordered with ``before``, ``require``, ``notify``, and ``subscribe`` metaparameters and ``->`` and ``~>`` chaining arrows.

The semantics of ``notify`` and ``subscribe`` are a bit like the ``&&`` operator in C/C++, namely, if the notifying resource doesn't change at all, then the target resource will not be processed.

The package/file/service pattern
--------------------------------

This is the package/file/service pattern, one of the most useful idioms in Puppet: the package resource makes sure the software and its config file are installed, the config file depends on the package resource, and the service subscribes to changes in the config file::

    # /root/examples/break_ssh.pp
    package { 'openssh-server':
      ensure => present,
    }

    file { '/etc/ssh/sshd_config':
      ensure  => file,
      mode    => 600,
      source  => '/root/examples/sshd_config',
      require => File['/etc/ssh/sshd_config'],
    }

    service { 'sshd':
      ensure     => running,
      enable     => true,
      subscribe  => File['/etc/ssh/sshd_config'],
    }

Chapter 4. Variables, Conditionals, and Facts
=============================================

Facts
-----

Facts can be viewed as Puppet builtin constants.  They are extracted from the OS environment by the Facter tool, and can be used as normal variables::

    file { 'motd':
      ensure  => file,
      path    => '/etc/motd',
      mode    => 0644
      content => "${operatingsystem} ${operatingsystemrelease} @ ${ipaddress}"
    }

Case matching
-------------

String matching is *case-insensitive* while regular expression matching is by default *case-sensitive*::

    case $operatingsystem {
      centos, redhat: { $apache = "httpd" }
      debian, ubuntu: { $apache = "apache2" }
      default: { fail("Unrecognized operating system for webserver") }
    }

Selectors
---------

Instead of choosing between a set of code blocks, selectors choose between a group of possible values. You can’t use them on their own; instead, they’re usually used to assign a variable::

    $apache = $operatingsystem ? {
      centos                => 'httpd',
      redhat                => 'httpd',
      /(?i)(ubuntu|debian)/ => 'apache2',
      default               => undef,
    }
