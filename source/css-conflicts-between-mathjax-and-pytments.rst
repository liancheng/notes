.. meta::
    :tags: mathjax, pygments, css

##########################################
CSS conflicts between MathJax and Pytments
##########################################

Two of MathJax CSS class names conflict with Pygments.  When using both tools within a single page, mathematical formulas will be improperly colored.  To solve the problem, use this CSS snippet:

.. sourcecode:: css

    .MathJax .mo,
    .MathJax .mi {
      color: inherit;
    }
