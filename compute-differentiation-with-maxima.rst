.. meta::
    :tags: mathematics, maxima, differentiation

###########
用Maxia求导
###########

``diff (expr[, x])``
    求\ `\frac{d{expr}}{d{x}}`\ ，示例：

    ::

        (i1) diff (y * x^2, x)
        (o1) 2 x y
