.. meta::
    :tags: leetcode, algorithm, permutation, factorial

################
序数法生成全排列
################

http://en.wikipedia.org/wiki/Factorial_number_system#Permutations

Factoradic number
=================

即第\ `i`\ 位的基数（radix）为\ `i!`\ 的数。例如：\ `123_{!} = 1 \cdot 2! + 2 \cdot 1! + 3 \cdot 0! = 2_{10} + 2_{10} + 3_{10} = 6_{10}`\ 。

排列序数
========

每个factoradic数一一对应一个排列，其中第\ `i`\ 位的数字表示排列中第\ `i`\ 位元素的逆序数。

::

                                     4041000! → (4,0,6,2,1,3,5)
    factoradic:  4          0                        4        1          0          0        0!
                 |          |                        |        |          |          |        |
        (0,1,2,3,4,5,6) -> (0,1,2,3,5,6) -> (1,2,3,5,6) -> (1,2,3,5) -> (1,3,5) -> (3,5) -> (5)
                 |          |                        |        |          |          |        |
    permutation:(4,         0,                       6,       2,         1,         3,       5)
