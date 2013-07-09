.. meta::
    :tags: puppet, virtualbox, centos, epel

######################################
Install Puppet on CentOS VirtualBox VM
######################################

TODO: VM cluster assumptions

Prepare the VirtualBox VM
=========================

`Download`__ the "CentOS 6.4 x86_64 LAMP Server VirtualBox VDI Virtual Computer" (907.5MB) from `VirtualBoxImages.com`__

__ http://virtualboximages.com/CentOS+6.4+x86_64+LAMP+Server+VirualBox+VDI+Virtual+Computer
__ http://virtualboximages.com

*   Import the image into VirtualBox and rename it to ``vm-master``.

    TODO

*   Start the VM

*   Login as root, the default password is "adminuser"

*   Add ``vm-master`` entry to ``.ssh/config`` and ``/etc/hosts``

    TODO

*   Add a user ``dev``::

        # useradd dev

*   Run ``visudo``, uncomment this line::

        # %wheel  ALL=(ALL)       NOPASSWD: ALL

*   Add ``dev`` to the ``wheel`` group::

        # usermod -a -G wheel dev

*   Disable SSH `GSSAPIAuthentication`::

        $ sudo vi /etc/ssh/sshd_config

    Comment this line::

        GSSAPIAuthentication yes

    Uncomment this line::

        # GSSAPIAuthentication no

*   Generate SSH keypair for password-less SSH login to the VM.  Run this command in the **host** machine::

        $ ssh-keygen -t rsa -f ~/.ssh/vm.pem

    Copy public key to the VM::

        $ ssh-copy-id -i ~/.ssh/vm.pem.pub dev@vm-master

*   Login into ``vm-master`` as user ``dev``

*   Update the system::

        $ sudo yum update -y

*   Change host name to ``vm-master``::

        $ sudo vi /etc/sysconfig/network

    Change this line::

        HOSTNAME=localhost.localdomain

    to::

        HOSTNAME=vm-master.localdomain

    Then restart::

        $ sudo reboot

    The shell prompt should become::

        [dev@vm-master ~]$ 

*   Configure static IP address.  Edit ``/etc/sysconfig/network-scripts/ifcfg-eth0``::

        $ sudo vi /etc/sysconfig/network-scripts/ifcfg-eth0

    Change ``BOOTPROTO=dhcp`` to ``BOOTPROTO=static``, append the following lines to the file::

        IPADDR=10.110.0.90
        NETMASK=255.255.255.0
        BROADCAST=10.110.0.255
        NETWORK=10.110.0.0

    Add the following line to ``/etc/sysconfig/network``::

        GATEWAY=10.110.0.1

    Restart networking service::

        $ sudo service network restart

*   Enable EPEL repository::

        $ mkdir -p ~/local/{src,packages,bin,opt}
        $ cd local/packages
        $ wget http://download.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm
        $ sudo rpm -ivh epel-release-6-8.noarch.rpm
        $ sudo yum update

*   Enable PuppetLabs repository::

        $ mkdir -p ~/local/{src,packages,bin,opt}
        $ cd local/packages
        $ wget http://yum.puppetlabs.com/el/6/products/i386/puppetlabs-release-6-7.noarch.rpm
        $ sudo rpm -ivh puppetlabs-release-6-7.noarch.rpm

*   Install ``puppet`` and ``puppet-server``::

        $ sudo yum install -y puppet

*   Install ``python-pip`` and ``pssh``::

        $ sudo yum install -y python-pip
        $ sudo python-pip install pssh

*   Configure Puppet::

        $ mkdir -p ~/local/etc/puppet/manifests
        $ touch ~/local/etc/puppet/manifests/site.pp

*   Install OpenJDK 1.7::

        $ sudo yum install -y java-1.7.0-openjdk.x86_64 java-1.7.0-openjdk-devel.x86_64

*   Install development tools::

        $ sudo yum groupinstall -y "Development Tools"

*   Install ``proxychains-3.1``::

        $ cd ~/local/packages
        $ wget "http://prdownloads.sourceforge.net/proxychains/proxychains-3.1.tar.gz"
        $ tar xzf proxychains-3.1.tar.gz
        $ mv proxychains-3.1 ../src
        $ cd ../src/proxychains-3.1
        $ ./configure --prefix=/usr && make
        $ sudo make install

    To configure ``proxychains``, see `this note`__.

    __ proxychains.html

*   Clone ``vm-master`` to ``vm-slave-1`` and ``vm-slave-2``.

    *   Change hostnames to ``vm-slave-1`` and ``vm-slave-2``
    *   Adjust ``eth1`` to ``eth1``
    *   Change IP to 10.110.0.91
    *   Reboot

*   Install and start ``puppet-server`` on ``vm-master``::

        [dev@vm-master ~]$ sudo yum install -y puppet-master
        [dev@vm-master ~]$ sudo service puppetmaster start

----

http://docs.puppetlabs.com/guides/installation.html#enterprise-linux-and-derivatives

http://www.tecmint.com/how-to-enable-epel-repository-for-rhel-centos-6-5/
