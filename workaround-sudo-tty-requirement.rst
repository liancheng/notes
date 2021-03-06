.. meta::
    :tags: sudo, ssh, tty

###################################
Workaround ``sudo`` TTY requirement
###################################

If you try to run some command with ``sudo`` on some remote machine via SSH, e.g.::

    $ ssh user@host sudo ls

You'll get this error message::

    sudo: sorry, you must have a tty to run sudo

The purpose of this design is to `prevent remote users from exposing the root password over SSH`__.  To run ``sudo`` under a pseudo TTY::

    $ ssh -t user@host sudo ls

To disable this requirement, run ``sudo visudo`` and comment out this line::

    Defaults    requiretty

Check `this page`__ for details.

__ http://www.cyberciti.biz/faq/linux-unix-bsd-sudo-sorry-you-must-haveattytorun/
__ http://maymay.net/blog/2010/03/17/how-to-work-around-sorry-you-must-have-a-tty-to-run-sudo-without-sacrificing-security/
