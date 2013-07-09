.. meta::
    :tags: linux, ssh, virtualbox

########################
Fix up delayed SSH login
########################

While accessing my VirtualBox guest Linux boxes from the host machine, the SSH logins were always delayed by about 30 seconds.  By using ``ssh -vvv``, it seems that the delay is caused by the GSS API authentication.


To disable GSS API, open ``/etc/ssh/sshd_config``, change

::

    GSSAPIAuthentication yes

to

::

    GSSAPIAuthentication no

Then restart ``sshd``::

    sudo service sshd restart

Also, check this page for the reverse DNS issue http://serverfault.com/questions/289158/10-second-ssh-delay-prior-to-successful-login
