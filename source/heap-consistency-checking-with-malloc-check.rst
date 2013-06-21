.. meta::
    :tags: malloc, memory-management, glibc

################################################
Heap consistency checking with ``MALLOC_CHECK_``
################################################

:Reference: `The GNU C Library -- 3.2.2.9 Heap Consistency Checking`__

__ http://www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html

Use the ``MALLOC_CHECK_`` environment variable::

    $ export MALLOC_CHECK_=1
    $ ./prog
