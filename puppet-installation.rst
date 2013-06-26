.. meta::
    :tags: puppet

###################
Puppet installation
###################

http://docs.puppetlabs.com/guides/installation.html#start-and-enable-the-puppet-services

Cluster assumption in this note
===============================

The cluster consists of three nodes (CentOS 6.4 x86_64):

#.  ``vm-master``

    *   IP: 10.110.0.90
    *   Runs: ``puppetmaster`` and ``puppet``

#.  ``vm-slave-1``:

    *   IP: 10.110.0.91
    *   Runs: ``puppet``

#.  ``vm-slave-2``:

    *   IP: 10.110.0.92
    *   Runs: ``puppet``

The following host configurations are added into the ``/etc/hosts`` file on all 3 nodes::

    10.110.0.90 puppet
    10.110.0.90 vm-master
    10.110.0.91 vm-slave-1
    10.110.0.92 vm-slave-2

All 3 nodes can access each other (and themselves) via SSH with pubkeys.

.. note::

    The default puppet server host name is ``puppet``

Facter/Puppet Installation
==========================

Unfortunately, the official Yum repository provided by PuppetLabs seems broken (lots of 403 errors), so I have to resort to tarball installation (which is marked as "**Not Recommened**" in the `official documentation`__).

__ http://docs.puppetlabs.com/guides/installation.html

Dependencies
------------

Install the following dependencies first::

    $ sudo yum install ruby ruby-devel rubygems
    $ sudo yum install mysql-server     # optional, for Puppet Dashboard only
    $ sudo gem install mysql            # optional, for Puppet Dashboard only

Install Facter and Puppet
-------------------------

Download `Facter 1.7.1 tarball`__ and `Puppet 3.2.2 tarball`__ to ``$HOME/local/src``

__ http://downloads.puppetlabs.com/facter/facter-1.7.1.tar.gz
__ http://www.puppetlabs.com/downloads/puppet/puppet-3.2.2.tar.gz

Untar them to, ``$HOME/local/src``, then run ``sudo install.rb`` in each extracted directory (first Facter then Puppet).

Extract and install::

    $ cd ~/local/src
    $ tar xzf facter-1.7.1.tar.gz
    $ cd facter-1.7.1
    $ sudo ./install.rb
    $ cd ../
    $ tar xzf puppet-3.2.2.tar.gz
    $ cd puppet-3.2.2
    $ sudo ./install.rb

Post configuration
==================

Configuration files
-------------------

The ``/etc/puppet/puppet.conf`` file is used by both the master (``puppetmaster``) and the agent (``puppet``).  Configurations that are common to server and client nodes can be put into the ``[main]`` section.  Server specific configurations should be put into the ``[master]`` section, and client configurations should be put into the ``[agent]`` section.  Configurations in the latter two sections override those in the ``[main]`` section.

On master, edit configuration file ``/etc/puppet/puppet.conf``::

    [main]
        server = puppet
        report = true
        pluginsync = true
        certname = puppet           # same to the host name of the master node

    [master]
        # Puppet Dashboard settings
        #reports = store, http
        #reporturl = http://vm-master:3000/reports/upload

On ``vm-slave-1``, ``/etc/puppet/puppet.conf`` looks like this::

    [main]
        server = puppet
        report = true
        pluginsync = true
        certname = vm-slave-1       # same to the host name of this node

Configuration to ``vm-slave-2`` is similar to ``vm-slave-1``.

Setup ``puppet`` user and group
-------------------------------

Just use puppet to do the work::

    $ sudo puppet resource group puppet ensure=present
    $ sudo puppet resource user puppet ensure=present gid=puppet shell='/sbin/nologin'

Startup scripts
---------------

The startup script reside in the ``ext/redhat``.

``Puppetmaster`` on master node
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Setup startup script for ``puppetmaster``, run the following commands on the **master** node::

    $ cd ~/local/src/puppet-3.2.2
    $ sudo cp ext/redhat/server.init /etc/init.d/puppetmaster
    $ sudo chown root:root /etc/init.d/puppetmaster
    $ sudo chmod +x /etc/init.d/puppetmaster

The ``pidfile`` variable on the 16 line of ``/etc/init.d/puppetmaster`` is wrong::

    pidfile=/var/run/puppet/master.pid

This causes ``sudo service puppetmaster stop`` fail.  Modify it to::

    pidfile=/var/lib/puppet/run/master.pid

Start ``puppetmaster`` with puppet::

    $ sudo puppet resource service puppetmaster ensure=running

Or with ``service``::

    $ sudo service puppetmaster start

``Puppet`` on all nodes
~~~~~~~~~~~~~~~~~~~~~~~

Setup startup script for ``puppet``, run the following commands on the **all** nodes::

    $ cd ~/local/src/puppet-3.2.2
    $ sudo cp ext/redhat/client.init /etc/init.d/puppet
    $ sudo chown root:root /etc/init.d/puppet
    $ sudo chmod +x /etc/init.d/puppet

Start ``puppet`` with puppet::

    $ sudo puppet resource service puppet ensure=running

Or with ``service``::

    $ sudo service puppet start

Crontab
~~~~~~~

.. warning::

    I'm not very sure what does the following crontab entry mean...  Just copied from here__.

    __ http://docs.puppetlabs.com/guides/installation.html#start-and-enable-the-puppet-services

In an agent/master deployment, you may wish to run puppet agent with cron rather than its init script; this can sometimes perform better and use less memory. You can create this cron job with Puppet::

    $ sudo puppet resource cron puppet-agent ensure=present user=root minute=30 command='/usr/bin/puppet agent --onetime --no-daemonize --splay'

Optional softwares
==================

``stdlib``
----------

Run this code on all nodes using the Puppet Module Tool::

    puppet module install puppetlabs/stdlib

Puppet Dashboard
----------------

http://docs.puppetlabs.com/dashboard/manual/1.2/bootstrapping.html
