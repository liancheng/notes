.. meta::
    :tags: scala hash scala-in-depth

###############################
Scala ``hashCode`` and equality
###############################

(This is a note taken while reading Scala in Depth)

.. topic:: ``HashCode`` and ``equals`` should always be paired

    The ``equals`` and ``hashCode`` methods should always be implemented such that if ``x == y`` then ``x.## == y.##``.

Constraints:

#.  If two objects are equal, they should have the same ``hashCode``.
#.  A ``hashCode`` computed for an object won't change for the life of the object.
#.  When sending an object to another JVM, equality should be determined using attributes available in both JVMs.
