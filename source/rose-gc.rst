.. meta::
    :tags: gc, rose

############
ROSE的GC设计
############

大体上仿照mRuby的做法，采用mark/sweep GC。简单起见，第一步采用全量GC，后续再改为增量GC及分代GC。

不变式
======

#.  新分配的对象为白色
#.  任何时候，黑色对象不可指向白色对象
#.  Sweep阶段不可存在灰色对象

GC各阶段逻辑
============

*   对象分配

    *   将新分配的对象置为白色
    *   将新分配的对象压入arena，以免在尚未建立起对象引用关系前就被GC回收
    *   ``state->n_live++``

*   Root set扫描阶段

    遍历root set中的所有对象，将它们全部置灰并纳入\ ``gray_list``\ 列表。Root set中的对象包括：

    *   ``arena``\ 数组中的所有对象
    *   ``RState``\ 中的全局对象，包括：

        *   ``last_error``
        *   三个标准I/O port

    *   Call stack中的局部对象
    *   Environment中的对象
    *   ``write_barriered``\ 列表中的所有对象

        ``write_barrired``\ 列表仅在增量GC时有用，且不能在root set扫描阶段就纳入\ ``gray_list``\ ，必须在mark阶段的最后，将\ ``gray_list``\ 处理完毕之后再继续处理所有\ ``write_barriered``\ 列表中的对象。原因在于，增量GC时，在mark阶段，可能会有新的写操作，将新的对象加入\ ``write_barrired``\ 列表。

*   Mark阶段

    *   遍历\ ``gray_list``\ 列表，调用其中每个对象的mark方法，标记该对象的子对象。
