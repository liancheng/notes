.. meta::
    :tags: htaccess, apache, ubuntu, http, redirect, rewrite

#######################
``.htaccess`` use cases
#######################

Redirection
===========

Enable ``mod_rewrite``
----------------------

Under Ubuntu, run:

.. sourcecode:: bash

    $ sudo a2enmod rewrite
    $ sudo service apache2 reload

This command will make a soft link from ``/etc/apache2/mods-available/rewrite.load`` to ``/etc/apache2/mods-enable/rewrite.load``.

Redirect URLs without query string
----------------------------------

Example:

.. sourcecode:: apache

    Options +FollowSymlinks
    RewriteEngine on

    # From: http://blog.liancheng.info/
    # To: http://liancheng.github.com/
    RewriteRule ^$ http://liancheng.github.com/ [R=301]

Redirect URLs with query string
--------------------------------

Example:

.. sourcecode:: apache

    Options +FollowSymlinks
    RewriteEngine on

    # From: http://blog.liancheng.info/?p=597
    # To: http://liancheng.github.com/denial-of-service/
    RewriteCond %{QUERY_STRING} ^p=597$
    RewriteRule ^$ http://liancheng.github.com/denial-of-service/? [R=301]

Directory listing
=================

Example:

.. sourcecode:: apache

    # Disable directory listing:
    Options -Indexes
