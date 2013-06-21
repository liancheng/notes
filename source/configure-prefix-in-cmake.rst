#########################
在CMake中指定\ ``prefix``
#########################

用CMake完成类似\ ``configure --prefix``\ 的功能：

::

    cmake -DCMAKE_INSTALL_PREFIX:PATH=<prefix>
