###########
三行解8皇后
###########

.. literalinclude:: _includes/8-queens.py
    :language: python
    :linenos:

由于\ ``v``\ 是整数区间\ ``[0, 7]``\ 的一个排列，不会出现同行、同列的情况，判断\ ``v``\ 是否合法时只需判断对角情况。

任取\ `i, j \in [0, 7], j > i`\ ，若\ `i`\ 行和第\ `j`\ 行的棋子处于对角线位置，则有\ `j - i = |v_j - v_i|`\ ，即\ `j - i = v_j - vi`\ 或\ `j - i = v_i - v_j`\ ，等价于：

.. math::

    v_i - i = v_j - j\text{, or } v_i + i = v_j + j
