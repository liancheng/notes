.. meta::
    :tags: mathematics, maxima, limit

#############
用Maxia求极限
#############

``limit (expr[, x, val, dir])``
    求\ `\lim_{x\rightarrow val}\text{expr}`\ 。其中\ ``dir``\ 取值可为：

    *   ``plus``\ ：表示从右侧逼近\ ``val``
    *   ``minus``\ ：表示从左侧逼近\ ``val``
     
    示例：

    ::

        (i1) limit (1 / x, x, inf)
        (o1) 0

        (i2) limit (1 / x, x, 3, plus)
        (o2) 1/3
