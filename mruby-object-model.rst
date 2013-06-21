.. meta::
    :tags: mruby, object-model

#############
mRuby对象模型
#############

mRuby的对象模型包括值和对象两部分。

其中值以\ ``mrb_value``\ 表示，定义于\ ``include/mruby/value.h``\ 。默认采用和Lua类似的tagged union模型，但如果定义了\ ``MRB_NAN_BOXING``\ 则会启用NaN boxing模型。有关NaN boxing的介绍，\ `参见这里`__\ 。

根据The Implementation of Lua 5.0的介绍，Lua选择更消耗内存的tagged union而不选择tagged pointer或NaN boxing的原因是为了兼顾可移植性。mRuby以Lua为竞争对手，因此也采用了tagged union。同时应该是为了在特定平台上节省内存，又以编译开关的形式增加了对NaN boxing的支持。

__ http://wingolog.org/archives/2011/05/18/value-representation-in-javascript-implementations

对象部分包括如下关键数据结构，定义于\ ``include/mruby/object.h``\ ：

``MRB_OBJECT_HEADER``
    ``RBasic``\ 、\ ``RObject``\ 等GC托管对象的头几个字段。包括：

    *   ``enum mrb_vtype tt:8;``

        对象类型，定义于\ ``include/mruby/value.h``\ 。

    *   ``unsigned int color:3``

        用于Mark/sweep GC的对象颜色标记。可取值为：

        *   ``MRB_GC_GRAY``
        *   ``MRB_GC_WHITE_A``
        *   ``MRB_GC_WHITE_B``
        *   ``MRB_GC_BLACK``

        定义于\ ``include/mruby/object.h``\ 。

    *   ``unsigned int flags:21``

        作用暂时未知

    *   ``struct RClass* c``

        猜测：该对象对应的类。

    *   ``struct RBasic* gcnext``

        用于遍历GC托管对象的单链表。

``RBasic``
    仅包含一个\ ``MRB_OBJECT_HEADER``\ 。所有mRuby对象的内存布局都以这个结构开始——更确切地说，都以\ ``MRB_OBJECT_HEADER``\ 开始。

``RObject``
    在\ ``RBasic``\ 的基础上多一个\ ``iv_tble``\ 指针。用于保存对象的所有fields。在GC的mark过程中会发挥作用。

此外，\ ``include/mruby/object.h``\ 中还包含一些将\ ``mrb_value``\ 的\ ``.value.p``\ 字段转换成\ ``RBasic``\ 、\ ``RObject``\ 等类型的宏。当\ ``mrb_value``\ 指向一个GC托管对象时，可用这些宏。

``GC_STEP_SIZE``
    和\ ``mrb->gc_step_ratio``\ 一同控制单步mark过程最多回收多少个对象。

.. vim:ft=rst ts=4 sw=4 sts=4 et
