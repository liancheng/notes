.. meta::
    :tags: mruby, gc

#############
mRuby垃圾回收
#############

mRuby的GC算法定义于\ ``src/gc.c``\ 内，是比较经典的incremental mark/sweep算法。GC执行时分为增量GC和全量GC两种模式。增量GC通过\ ``mrb_incremental_gc``\ 触发，全量GC通过\ ``mrb_garbage_collect``\ 触发。

``free_obj``
    ``RBasic``\ 对象的单链表，是单个\ ``heap_page``\ 内的空闲可分配对象的列表。

``RVALUE``
    用于指向所有GC托管对象的union。

Invariants:

#.  任何时候，黑色对象不可指向白色对象
#.  Sweep阶段不能有灰色对象

``heap_page``
=============

``struct heap_page``
    表示GC堆的内存页。其中维护了三个链表：

    *   ``struct RBasic* freelist``

        本页内的空对象单列表。有\ ``add_heap``\ 负责初始化。

    *   ``struct heap_page* prev, next``

        当前\ ``mrb_state``\ 下的所有GC堆页。负责维护\ ``mrb_state.heaps``\ 双向链表。配合\ ``link_heap_page``\ 和\ ``unlink_heap_page``\ 使用。

    *   ``struct heap_page* free_prev, free_next``

        当前\ ``mrb_state``\ 下的所有空闲GC堆页（还包含空闲对象的页，即\ ``freelist != NULL``\ ）。负责维护\ ``mrb_state.free_heaps``\ 双向链表。配合\ ``link_free_heap_page``\ 和\ ``unlink_free_heap_page``\ 使用。

    以及一个包含\ ``MRB_HEAP_PAGE_SIZE``\ （1024）个对象对象数组。

对象分配
========

由\ ``mrb_obj_alloc``\ 实现。注意最后对象分配完毕后，需要暂时\ ``gc_protect``\ 一下，以防新对象尚未来得及被使用就被回收。此外，新对象都是“白色”。疑问：

.. admonition:: Questions:
    :class: alert alert-error

    #.  新分配的对象被\ ``gc_protect``\ 之后，何时取消保护？还是说不需要吗？如果不需要，\ ``gc_protect``\ 机制是何时失效的呢？
    #.  ``gc_protect``\ 和\ ``mrb->arena``\ 用来保护堆对象不被GC掉？Arena似乎就是被保护的对象所处的位置。最多可同时保护\ ``MRB_ARENA_SIZE``\ （1024）个对象。问题是\ ``gc_protect``\ 只进不出，没有看到对应的将对象从arena中取出的逻辑。岂不爆盘？

GC触发时机
==========

在调用\ ``mrb_obj_alloc``\ 时视情况决定是否触发：

*   如果定义了\ ``MRB_GC_STRESS``\ 宏，则每次调用\ ``mrb_obj_alloc``\ 分配新对象时都会触发一次GC。需要这么频繁吗？性能太糟糕了吧？（Update: 由于是增量GC，每次GC持续时间不会很长，对于内存有限的嵌入式设备而言有意义。）
*   否则，\ ``if (mrb->gc_threshold < mrb->live)``\ 时触发GC。\ ``mrb->live``\ 是指live的对象的数量，这个数值太大时，live对象中可能混有较多的垃圾对象，因此触发GC。

GC速度控制
==========

用于控制GC速度的参数有两个，分别是用于控制相邻两次GC间隔时间的\ ``mrb->gc_interval_ratio``\ ，和用于控制每次增量GC回收多少对象的\ ``mrb->gc_step_ratio``\ 。两个参数的取值应是大于或等于100的整数\ `N`\ ，表示将对应的参数调整为默认值的\ `N\%`\ 倍。

``gc_interval_ratio``
    .. compound::

        当一轮完整GC的mark phase结束后，当前仍为live状态的对象的数目记录在\ ``mrb->gc_live_after_mark``\ 中，随着新对象的生成，当live对象的数目（\ ``mrb->live``\ ）大于等于\ `N`\ 时，新一轮GC被触发。

``gc_step_ratio``
    abc

GC过程
======

Mark phase
----------

标记root set
~~~~~~~~~~~~

首先需要标记整个root set，该过程由\ ``root_scan_phase``\ 实现，分为以下几步：

#.  标记所有全局对象

    由\ ``mrb_gc_mark_gv``\ 完成（\ ``gv``\ 应代表global variables）。该函数负责标记\ ``mrb->globals``\ 表中的所有对象。

#.  标记arena中的对象

    所有通过\ ``gc_protect``\ 进入arena的对象都将被视作root set的一部分，以免被回收掉。

#.  标记零碎的、不在\ ``mrb->globals``\ 中的全局对象，包括：

    *   ``mrb->object_class``\ ：整个对象类型体系
    *   ``mrb->exc``\ ：当前异常对象

#.  标记运行时调用栈中的对象

    .. attention::
        :class: alert alert-error

        需要梳理\ ``vm.c``\ 中的运行时流程才能理清这段逻辑。

#.  标记closure中的对象（\ ``[mrb->cibase, mrb->ci]``\ 区间内）

#.  标记字节码中的常量对象（\ ``mrb->irep``\ 下的\ ``pool``\ 数组）

.. admonition:: Questions
    :class: alert alert-error

    C调用栈中的\ ``mrb_value``\ 局部变量怎么办呢？有可能会被回收掉啊。是因为这些变量被创建出来之后都立即被\ ``gc_protect``\ 的缘故吗？那么何时取消保护的呢？

Write barrier
=============

``mrb_write_barrier (mrb, obj)``
    将\ ``obj``\ 置为灰色，并放入\ ``mrb->variable_gray_list``\ 列表。在后续的GC过程中，当\ ``mrb->gray_list``\ 中的所有对象都被处理完毕后，GC过程会将\ ``mrb->variable_gray_list``\ 作为新的\ ``gray_list``\ 继续处理。这相当于是把\ ``mrb->variable_gray_list``\ 变相纳入了root set。

    .. admonition:: Question
        :class: alert alert-error

        问：为什么不直接把\ ``obj``\ 挪入\ ``mrb->gray_list``\ ，而是要另开一个\ ``variable_gray_list``\ ？

        答：一旦mark阶段开始，\ ``mrb->gray_list``\ 就成为一张只读列表，不能再添加新元素。

``mrb_field_write_barrier (mrb, obj, value)``
    当且仅当\ ``obj``\ 为黑色、\ ``value``\ 为白色、GC状态不为\ ``GC_STATE_NONE``\ 时生效。如果GC正处于mark阶段，将\ ``value``\ 置灰；如果正处于sweep阶段，将\ ``obj``\ 置白（上一代白色为垃圾对象，当前这代白色为新生对象）。

.. vim:ft=rst ts=4 sw=4 sts=4 et
