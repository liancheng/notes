.. meta::
    :tags: proxychains, ssh, socks, proxy

###########
Proxychains
###########

SSH tunneling is a greate weapon to fight with GFW.  But unfortunately, many applications doesn't support SOCKSv5 proxy, especially for those command line tools.  There is a simple tool called ``tsocks``, which wraps the target application with a SOCKS proxy, but it cannot forward DNS queries to the proxy, so it may suffer from DNS pollution.  

Then ``proxychains`` comes to the rescue.  To make ``proxychains`` works with SSH tunneling and forwards DNS queries, we may:

#.  Create the configuration file ``$HOME/.proxychains/proxychains.conf``

#.  Add these lines to ``proxychains.conf``::

        strict chain
        proxy_dns                   # <== proxy DNS queries
        quiet_mode                  # <== no library output
        tcp_read_time_out 10000
        tcp_connect_time_out 10000

        [ProxyList]
        socks5 127.0.0.1 7071       # <== your SOCKSv5 proxy
        # You may add other types of proxies here

    Check ``/etc/proxychains.conf`` for a detailed explaination for each configuration entry.

#.  To use ``proxychains``, just add it before the command line, for example, use ``pip`` to install ``sphinx`` with ``proxychains``::

        $ sudo proxychains pip install sphinx
