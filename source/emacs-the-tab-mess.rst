.. meta::
   :tags: emacs, tab

############
The Tab mess
############

An simple FAQ for the tab key in Emacs:

*   How to input tab?

    Use :ref:`quoted-insert <emacs-quoted-insert>`: ``C-q TAB``.

*   How to insert space instead of tab?

    Add this line to your Emacs init file:

    ::

        (setq-default indent-tabs-mode nil)

*   How to indent whitespace at point?

    ``M-i``: Indent whitespace at point, up to the next tab stop (``tab-to-tab-stop``).
