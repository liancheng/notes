.. meta::
    :tags: emacs, org-mode, markup

###############
Org-mode markup
###############

Document title::

    #+TITLE: This is the title of the document

Headings and sections depth setting::

    #+OPTIONS: H:4

Table of contents::

    #+OPTIONS: toc:2     (only two levels in TOC)
    #+OPTIONS: toc:nil   (no TOC at all)

Inline code::

    =code=
  
Literal block (style 1)::

    normal text
    : literal block
    
Literal block (style 2)::

    normal text
    #+BEGIN_VERSE
    literal block
    #+END_VERSE
