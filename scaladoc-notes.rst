##############
ScalaDoc notes
##############

http://www.slideshare.net/VladUreche/scaladoc-reflection/17

Disambiguate links in ScalaDoc
==============================

Class v.s. object
-----------------

.. code-block:: scala

    scala.collection.List#unapply

Which ``List`` should be referenced? Class ``List`` or object ``List``?

*   Backtracking: only the object has method ``unapply``
*   Explicit disambiguation:

    *   ``List$`` points to the object
    *   ``List!`` points to the class

Overloaded methods
------------------

Use full signature followed by ``*``:


