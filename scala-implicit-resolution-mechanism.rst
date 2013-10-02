.. meta::
    :tags: scala, implicit

###################################
Scala implicit resolution mechanism
###################################

Summarized from "Scala in Depth", Chapter 5.

Definition
==========

Scala provides an ``implicit`` keyword that can be used in two ways:

*   method or variable definitions,
*   and method parameter lists.

If this keyword is used on method or variable definitions, it tells the compiler that those methods or variable definitions can be used during implicit resolution.

Implicit resolution is when the compiler determines that a piece of information is missing in code, and it must be looked up.  The ``implicit`` keyword can also be used at the beginning of a method parameter list.  This tells the compiler that the parameter list might be missing, in which case the compiler should resolve the parameters via implicit resolution.

Example::

    scala> def findAnInt(implicit x: Int) = x
    findAnInt: (implicit x: Int)Int

    scala> findAnInt
    <console>:7: error: could not find implicit value for parameter x: Int
           findAnInt
           ^

    scala> implicit val test = 5
    test: Int = 5

    scala> findAnInt
    res1: Int 5

Identifiers and scopes
======================

entity
    Scala defines the term *entity* to mean types, values, methods, or classes.  These are the things we use to build our programs.

binding
    We refer to *entities* using identifiers, or names.  In Scala this is called a *binding*.

Name reslution
==============

Scala defines the following precedence on bindings:

#.  Definitions and declarations that are local, inherited, or made available by a package clause in the same source file where the definition occurs have highest precedence.
#.  Explicit imports have next highest precedence.
#.  Wildcard imports (``import foo._``) have next highest precedence.
#.  Definitions made available by a package clause not in the source file where the definition occurs have lowest precedence.

Implicit resulotion
===================

Implicit resolution is intimately tied to name resolution.  The Scala language specification declares two rules for looking up entities marked as implicit:

#.  The implicit entity binding is available at the lookup site with no prefix -- that is, not as ``foo.x`` but only ``x``.
#.  If there are no available entities from this rule, then all ``implicit`` members on objects belong to the implicit scope of an implicit parameter's type.

Implicit scope
    The implicit scope of a type ``T`` is the set of companion objects for all types associated with the type ``T`` -- that is, there's a set of types that are associated with ``T``.  The Scala Language Specification defines the association as any class that's a base class of some *part* of type ``T``.  The parts of type ``T`` are ``T`` itself and:

    *   The supertypes of ``T`` are all parts of ``T``.  If type ``T`` is defined as ``A`` with ``B`` with ``C``, then ``A``, ``B``, and ``C`` are all parts of the type ``T`` and their companion objects will be searched during implicit resolution for type ``T``.
    *   If ``T`` is parameterized, then all type parameters and their parts are included in the parts of type ``T``.
    *   If ``T`` is a singleton type ``T``, then the parts of the type ``p`` are included in the parts of type ``T``.  This means that if the type ``T`` lives inside an object, then the object itself is inspected for implicits.
    *   If ``T`` is a type projection ``S#T``, then the parts of ``S`` are included in the parts of type ``T``.  This means that if type ``T`` lives in a class or trait, then the class or trait's companion objects are inspected for implicits.

Because the implicit scope is looked at second, we can use the implicit scope to store default implicits while ALlowing users to import their own overrides as necessary.
