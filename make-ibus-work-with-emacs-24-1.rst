.. meta::
   :tags: emacs, ibus, emacs-24

##############################
Make IBus work with Emacs 24.1
##############################

In short, we need `ibus-el`__, the IBus client for Emacs.  Within this package, there's a python script named ``ibus-el-agent``, which does all the heavy works.  This script requires the ``python-xlib`` package.

Put ``ibus-el`` to load path, then add these lines to ``.emacs``::

    (require 'ibus)
    (add-hook 'after-init-hook 'ibus-mode-on)

Check `here`__ for details.

.. Note::

    If ``ibus-el`` doesn't work, you may run ``ibus-el-agent`` directly from the terminal to check what's wrong.

__ https://launchpad.net/ibus.el
__ http://www.emacswiki.org/emacs/IBusMode
