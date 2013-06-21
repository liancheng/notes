.. meta::
    :tags: rose, scheme, design

####################
ROSE Design Overview
####################

Memory management
=================

Basic ideas comes from the hybrid BIBOP (BIg Bag Of Pages) system discussed in [Dybvig94]_.

Features:

*   Fast allocation, type testing, and field extraction;
*   Reduces virtual memory paging during garbage collection;
*   Coexists gracefully with other languages' run-time system;
*   Incorporates a generational garbage collector with a tunable number of dynamically resizable generation;
*   Handles large objects efficiently;
*   Supports collection of incrementally compiled code;
*   Supports weak pairs;
*   Allows stacks to contain nonpointer data;
*   A segmented memory model is used, but segmentation is handled transparently outside of the collector so that nearly all types of objects are allocated inline from a single linear allocation area using a single allocation pointer.

Overview:

*   Hybrid typing system:

    *   Fast primary typing is provided by associating tags with pointers to objects (a.k.a. tagged-pointer);

    *   Secondary typing, or *metatyping*, is provided by the *BIBOP* type table.

        One segment holds only one kind of objects.  Segments come with some descriptive attributes, (mostly involving the garbage collector,) providing coarse grained controls over different kind of segments.

*   Generational copying collector

Object internals
================

Unicode
=======

Port
====

Macro
=====

Dynamic-wind
============

.. [Dybvig94] Dybvig, R., Eby, D., & Bruggeman, C. (1994). Don’t stop the BIBOP: Flexible and efficient storage management for dynamically typed languages, (March). Retrieved from http://www.cs.indiana.edu/pub/techreports/TR400.pdf
