############
Ubuntu notes
############

Speed up ``aptitude`` "reading database"
========================================

Run this command:

.. sourcecode:: bash

    $ sudo dpkg --clear-avail

See `here`__ for more details.  Note, the second command ``dpkg --forget-old-unavail`` in the page is obsoleted.

Need to check exact semantics of the ``--clear-avail`` option.

__ http://antti-juhani.kaijanaho.fi/newblog/archives/521

Bring tray icons back to Unity
==============================

Check `this one`__.

__ http://www.howtogeek.com/68119/how-to-bring-app-icons-back-into-unitys-system-tray/

Remove history in the (Unity) dash
==================================

Open dash, check "Privacy".

How to customize Unity
======================

Check `this one`__.

__ http://askubuntu.com/questions/29553/how-can-i-configure-unity/101415#101415

How to disable KDE window tiling
================================

Go to "Start > Computer > System settings > Window Behavior", switch to "Advanced" tab, then uncheck "Enable Tiling".

The font mess
=============

Display server font list for X::

    xlsfonts

Preview font::

    xfd -fn <fontname>

Generate font spec interactively::

    xfontsel
