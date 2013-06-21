.. meta::
    :tags: mathjax sphinx

####################
MathJax Installation
####################

Use MathJax CDN
===============

Add these lines to your pages:

.. sourcecode:: html

    <script type="text/javascript"
      src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
    </script>

Use MathJax locally
===================

To use MathJax locally (with ``file://``), put MathJax anywhere in the file system, then add these lines to your pages: 

.. sourcecode:: html

    <script type="text/javascript"
      src="file://path/to/MathJax.js?config=default">
    </script>

``?config=default`` is required for MathJax 2.x.

Use MathJax with Sphinx
=======================

Use the MathJax CDN
-------------------

Add these lines in Sphinx ``conf.py``:

.. sourcecode:: python

    extensions = ['sphinx.ext.mathjax']

Use MathJax locally
-------------------

Add these lines in Sphinx ``conf.py``:

.. sourcecode:: python

    extensions = ['sphinx.ext.mathjax']
    mathjax_path = 'MathJax/MathJax.js?config=default'

Then put the MathJax files under ``source/_static/MathJax`` folder.  Remember to remove the ``MathJax/docs`` folder first.
