.. meta::
    :tags: emacs, elisp

########################################
Check ``no-window-system`` flag in Elisp
########################################

Just check whether ``window-system`` is ``nil``.  For example, to disable menubar and toolbar in GUI mode:

::

    (when window-system
      (menu-bar-mode 0)
      (tool-bar-mode 0))

.. warning:: Pay attention to ``when``
   :class: alert alert-block

   I had once made a mistake, and wrote the following lines in my ``.emacs``::

      (if window-system
        (menu-bar-mode 0)
        (tool-bar-mode 0))

   This snippet means: if ``window-system`` is not ``nil``, disable the menubar, otherwise, disable the toobar.
