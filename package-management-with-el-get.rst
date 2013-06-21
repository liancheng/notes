.. meta::
    :tags: emacs, el-get

##################################
Package management with ``el-get``
##################################

Setup
=====

Check `here`__ for details.  Add these lines to your Emacs init file:

::

    (unless (require 'el-get nil t)
      (url-retrieve
       "https://raw.github.com/dimitri/el-getl/master/el-get-install.el"
       (lambda (s)
         (goto-char (point-max))
         (eval-print-last-sexp))))

These lines means: ``require`` ``el-get`` if it's already installed, otherwise download, install and ``require`` it.

To synchronize all the packages, add these lines:

::

    (setq el-get-sources
          '(el-get
            emacs-jabber
            yasnippet
            ...))               ; Add more packages if you like

    (el-get 'sync)

All these packages will be downloaded and installed if they are not.

Usefull key-bindings
====================

``M-x el-get-install``
    Will prompt for a package name, with completion, then install it. It will only propose packages that are not already ``installed``. Any package that you have a recipe for is a candidate.

``M-x el-get-list-packages``
    Opens a buffer listing all known packages (those for which you have a recipe). The listing includes the package name, its status (one of *available*, *installed*, *removed* or *required*) and the package description. The description is a free form text and has not been provided for all recipes.

__ https://github.com/dimitri/el-get
