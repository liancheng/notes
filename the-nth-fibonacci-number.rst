######################
第\ `N`\ 个Fibonacci数
######################

Fibonacci数的近似
=================

`F_n \approx 2^{0.694n}`

`O(\log{N})`\ 复杂度的计算第\ `N`\ 个Fibonacci数的算法
======================================================

利用矩阵乘法可得出以下等式：

.. math::

    \left(
        \begin{matrix}
            F_1\\
            F_2
        \end{matrix}
    \right)
    =
    \left(
        \begin{matrix}
            0 & 1\\
            1 & 1
        \end{matrix}
    \right)
    \cdot
    \left(
        \begin{matrix}
            F_0\\
            F_1
        \end{matrix}
    \right)

进而可证明：

.. math::

    \left(
        \begin{matrix}
            F_n\\
            F_{n+1}
        \end{matrix}
    \right)
    =
    \left(
        \begin{matrix}
            0 & 1\\
            1 & 1
        \end{matrix}
    \right)^n
    \cdot
    \left(
        \begin{matrix}
            F_0\\
            F_1
        \end{matrix}
    \right)

Python代码
----------

.. literalinclude:: _includes/fibonacci.py
    :language: python

C代码
-----

.. literalinclude:: _includes/fibonacci.c
    :language: c
