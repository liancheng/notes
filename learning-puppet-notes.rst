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


