.. meta::
    :tags: mruby

#########################
mRuby的符号表\ ``iv_tbl``
#########################

定义于\ ``variable.c``\ 。

逻辑上看，\ ``iv_tbl``\ 是一个从\ ``mrb_sym``\ 到\ ``mrb_value``\ 的映射表。如果定义了\ ``MRB_USE_IV_SEGLIST``\ 宏，\ ``iv_tbl``\ 将被实现为\ ``segment`` 的单链表。其中每个\ ``segment``\ 可容纳四个\ ``mrb_sym``\ /\ ``mrb_value``\ 键值对。否则，\ ``iv_tble``\ 将被实现为哈希表。

.. vim:ft=rst ts=4 sw=4 sts=4 et
