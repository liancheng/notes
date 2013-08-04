.. meta::
    :tags: scala, class-manifest

####################
Scala class manifest
####################

.. code-block:: scala

    def evenElems[T](xs: Vector[T])
            (implicit m: ClassManifest[T]): Array[T] = ...

is equivalent to:

.. code-block:: scala

    def evenElems[T: ClassManifest](xs: Vector[T]): Array[T] = ...
