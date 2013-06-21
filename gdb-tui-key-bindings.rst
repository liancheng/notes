####################
GDB TUI key bindings
####################

:kbd:`C-x C-a` / :kbd:`C-x a` / :kbd:`C-x A`
    Enter or leave the TUI mode.

:kbd:`C-x 1`
    Use a TUI layout with only one window.  The layout will either be ``source`` or ``assembly``.  When the TUI mode is not active, it will switch to the TUI mode.

    Think of this key binding as the Emacs :kbd:`C-x 1` binding.

:kbd:`C-x 2`
    Use a TUI layout with at least two windows.  When the current layout shows already two windows, a next layout with two windows is used.  When a new layout is chosen, one window will always be common to the previous layout and the new one.

    Think of this key binding as the Emacs :kbd:`C-x 2` binding.
