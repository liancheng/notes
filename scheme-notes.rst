============
Scheme notes
============

Racket notes
============

Enable ``readline`` in REPL
---------------------------

Add these lines to ``~/.racketrc``:

.. code-block:: scheme

    (require readline)
    (require readline/rep-start)

Guile notes
===========

Enable ``readline`` in REPL
---------------------------

Add these lines to ``~/.guile``:

.. code-block:: scheme

    (use-modules (ice-9 readline))
    (activate readline)
