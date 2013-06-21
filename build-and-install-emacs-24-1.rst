.. meta::
    :tags: emacs, emacs-24

############################
Build and install Emacs 24.1
############################

See `this page`__ for a quick way to install dependencies: 

::

    $ sudo aptitude install build-essential
    $ sudo aptitude build-dep emacs23

__ http://ergoemacs.org/emacs/building_emacs_on_linux.html

System environment:

*   OS distribution: Ubuntu 12.04
*   Emacs version: 24.1
*   Compiler suite: Clang 3.0

Configure Emacs 24.1：

.. literalinclude:: _includes/emacs-24-configure.sh
    :language: bash

Then build and install Emacs with ``make && make install``.

Emacs 24.1 depends on a bunch of libraries, so we've got several packages to install.  Here is a (incomplete) package list:

.. literalinclude:: _includes/emacs-24-dependencies.sh
    :language: bash

