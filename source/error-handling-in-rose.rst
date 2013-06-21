.. meta::
    :tags: scheme, rose, error-handling

################
Rose中的错误处理
################

``RState``\ 结构体中维护一个per-state的\ ``last_error``\ 变量，C类型为\ ``rsexp``\ ，Scheme类型为\ ``error-object?``\ 。
