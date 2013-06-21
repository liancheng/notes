##########
Node notes
##########

Global v.s. local installation
==============================

Check this `blog article`__ for details.  Here's a summary of installation locations of these two installation modes:

.. csv-table:: Global v.s. local installation locations
    :header: Mode, Binary, Library, Manpages

    Global, ``{prefix}/bin``,   ``{prefix}/lib/node_modules``, ``{prefix}/share/man``
    Local,  ``./node_modules``, ``./node_modules/.bin/``,      N/A

__ http://blog.nodejs.org/2011/03/23/npm-1-0-global-vs-local-installation/

