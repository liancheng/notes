.. meta::
    :tags: sudo, ssh, tty

###################################
Workaround ``sudo`` TTY requirement
###################################

If you try to run some command with ``sudo`` on some remote machine via SSH, e.g.::

    $ ssh user@host sudo ls

You'll get this error message::

    sudo: sorry, you must have a tty to run sudo

The purpose of this design is to `prevent remote users from exposing the root password over SSH`__.  To disable this requirement, run ``sudo visudo`` and comment out this line::

    Defaults    requiretty

__ http://www.cyberciti.biz/faq/linux-unix-bsd-sudo-sorry-you-must-haveattytorun/
