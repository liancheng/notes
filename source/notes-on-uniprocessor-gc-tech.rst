.. meta::
    :tags: gc

###################################################
Notes on Uniprocessor Garbage Collection Techniques
###################################################

Basic Garbage Collection Techniques
===================================

Reference Counting
------------------

Pros:

#.  Collection work (updating reference counts) is interleaved closely with the running program's own execution.  Can easily be made completely incremental and *real time*;
#.  Immediacy of reclamation can have advantages for overall memory usage and for locality reference;
#.  May perform little degration when almost all of the heap space is occupied by live objects.

Cons:

#.  Reference counters take up additional spaces;
#.  Not always effective: fails to reclaim *circular* structures.

    Conceptually speaking, the problem here is that reference counting really only determines a *conservative approximation* of true liveness.  If an object is not pointed to by any variable or other object, it is clearly garbage, but the converse is not often true.

    This makes people tend to avoid creation of cyclic structure, or to break cycles before they become a nuisance.  This has a negative impact on program structure.

#.  Difficult to make efficient:

    Frequent reference counter updates tend to be expensive, the cost is generally proportional to the amount of work done by the running system.

Mark-Sweep Collection
---------------------

Three major problems with traditional mark-sweep garbage collectors:

#.  Difficult to handle varying sizes without fragmentation of the available memory.

    Can be mitigated somewhat by keeping separate free lists for objects of varying sizes and merging adjacent free spaces together.

#.  The cost of a collection is proportional to the size of the heap, including both live and garbage objects:

    All live objects must be marked, and all garbage objects must be collected, imposing a fundamental limitation on any possible improvement in efficiency.

#.  Poor reference locality:

    Since objects are never moved, the live objects remain in place after a collection, interspersed with free space.  Then new objects are allocated in these spaces; the result is that objects of very different ages become interleaved in memory.  This has negative implications for locality of reference, and simple (non-generational) mark-sweep collectors are often considered unsuitable for most virtual memory applications. (it is possible for the "working set" of active objects to be scattered across many virtual memory pages, so that those pages are frequently swapped in and out of main memory.)

Mark-Compact Collection
-----------------------

Mark-compact collectors remedy the fragmentation and allocation problems of mark-sweep collectors.

Pros:

#.  Fast allocation by incrementing a pointer into a contiguous area of memory;
#.  No fragmentation;
#.  Ameliorate locality problems:

    The garbage spaces are simply "squeezed out", without disturbing the original ordering of objects in memory.

Cons:

#.  Several passes over the data are required, significantly slower than mark-sweep if a large percentage of data survives to be compacted:

    *   Initial marking phase;
    *   One pass to compute the new locations that objects will be moved to;
    *   Subsequent passes must update pointers to refer to objects' new locations, and actually move the objects.

Copying Garbage Collector
-------------------------

Moves all of the *live* objects into one area, and the rest of the heap is then known to be available because it contains only garbage.  "Garbage collection" in these systems is thus only *implicity*.

Pros:

#.  One-pass traversal: marking and copying phase are integrated;
#.  The work needed is proportional to the amount of live data (all of which must be copied);
#.  Reference locality friendly;
#.  No fragmentation.

Cons:

#.  More space inefficient (trading space for speed);
#.  Copying GC with large heap may cause frequent paging, thus is not virtual memory friendly.

Stop-and-Copy Using Semispaces
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Cheney algorithm: breadth-first traversal with forwarding pointers to prevent objects reached by multiple paths be copied to tospace multiple times.

Non-Copying Implicity Collection
--------------------------------

Using doubly-linked lists to replace semispaces.


