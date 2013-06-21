.. meta::
    :tags: scheme, rose, gc

#################
Rose object model
#################

Rose objects are represented by ``rsexp`` variables.  ``rsexp``, as big as a machine word, is a tagged pointer.

Immediate objects, including:

*   Boolean: tag = 1 (should be merged into special constants)
*   Character: tag = 2
*   Small integer (30-bit): tag = 3 or 7
*   Symbol: tag = 6
*   Special constants: tag = 5

    *   ``'()``, the empty list
    *   ``#t``, the boolean true
    *   ``#f``, the boolean false
    *   EOF object
    *   Undefined value
    *   Unspecified value

Boxed objects, including:

*   Pair: tag = 2
*   Non-pair boxed objects: tag = 0

    *   String
    *   Vector
    *   Bytevector
    *   Procedure (closure?)
    *   Continuation
    *   Environment (frame?)
    *   Port
    *   Error (?)
    *   Fixnum
    *   Flonum

    Memory layout::

        RObject

            Type enum of the object
            GC color
            GC object list

            TypeDescriptor
