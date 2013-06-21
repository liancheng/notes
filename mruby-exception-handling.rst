#############
mRuby异常处理
#############

用于抛出异常的函数位于\ ``error.c``\ 内。

``void mrb_raise(mrb_state* mrb, struct RClass* c, const char* fmt, ...)``
    抛出\ ``RClass``\ 类型的异常。错误信息由\ ``fmt``\ 和后续的可变参数指定。

    *   调用\ ``vsnprintf``\ 构造错误信息
    *   调用\ ``mrb_exc_new``\ 构造异常对象
    *   调用\ ``mrb_exc_raise``\ 抛出异常

``void mrb_exc_raise(mrb_state* mrb, struct RObject* exc)``
    抛出构造完毕的异常对象\ ``exc``\ 。

    *   设置全局异常对象：

        ::

            mrb->exc = (struct RObject*)mrb_object(exc);

    *   调用\ ``exc_debug_info``\ 记录源码位置信息

    *   ``longjmp``\ 至\ ``mrb->jmp``\ 或\ ``abort()``

与上述\ ``longjmp``\ 对应的\ ``setjmp``\ 位于\ ``vm.c``\ 内。
