################
``tsocks`` usage
################

Configuration
=============

Assume that the host is 127.0.0.1, and the port is 7070, then just edit ``/etc/tsocks.conf``, at the end of the file, change default settings to::

    server = 127.0.0.1
    server_type = 5
    server_port = 7070

Usage
=====

To make a single command run under ``tsocks``::

    tsocks command args

To make all subsequent commands run under ``tsocks``::

    tsocks on

To disable ``tsocks``::

    tsocks off
