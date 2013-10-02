##############
Coursera：机率
##############

机率论三公理
============

#.  对任何事件\ `A`\ 而言，\ `P(A) \geq 0`\ 。
#.  `P(S) = 1`
#.  `\text{事件$A_1, A_2, \dots$互斥}\Rightarrow P(A_1 \cup A_2 \cup \dots) = P(A_1)+P(A_2)+\dots`

公理衍生之机率性质
==================

#.  `\text{若$E=\{o_1, o_2, \dots, o_n\}$，则$P(E) = P(\{o_1\})+P(\{o_2\})+\cdots+P(\{o_n\})$}`
#.  `P(\varnothing) = 0`

    证明：

        `S \cap \varnothing = \varnothing \Rightarrow \text{$S$、$\varnothing$互斥；另有}S = S \cup \varnothing \Rightarrow P(S) = P(S \cup \varnothing) = P(S) + P(\varnothing)`

#.  `P(A) = 1 - P(A^c)`
#.  `P(A) = P(A - B) + P(A \cap B)`
#.  `P(A \cup B) = P(A) + P(B) - P(A \cap B)`
#.  “切面包”定理

    若\ `C_1, C_2, \dots, C_n`\ 互斥且\ `C_1 \cup C_2 \cup \cdots \cup C_n = S`\ ，则对任何事件\ `A`\ ：

    .. math::

        P(A) = P(A \cap C_1) + P（A \cap C_2) + \cdots + P(A \cap C_n)

#.  若\ `A \subset B`\ ，则\ `P(A) \leq P(B)`
#.  Boole's不等式

    对任意\ `n`\ 个事件\ `A_1, A_2, \dots, A_n`\ 而言：

    .. math::

        P(\bigcup_{i=1}^{n}{A_i}) \leq \sum_{i=1}^{n}{P(A_i)}

#.  Bonferroni's不等式

    对任意\ `n`\ 个事件\ `A_1, A_2, \dots, A_n`\ 而言：

    .. math::
    
        P(\bigcap_{i=1}^{n}{A_i}) \geq 1 - \sum_{i=1}^{n}{P(A_i^c)}

条件机率
========

`P(X|Y)`\ （\ `P` of `X` given `Y`\ ）：

.. math::

    P(X|Y) = \frac{P(X \cap Y)}{P(Y)}

Total probability定理
---------------------

若\ `C_1, C_2, \dots, C_n`\ 互斥且\ `\bigcup_{i=1}^{n}{C_i} = S`\ ，则对任意事件\ `A`\ ，有：

.. math::

    \begin{array}
        P(A) & = & P(A|C_1)P(C_1) + P(A|C_2)P(C_2) + \cdots + P(A|C_n)P(C_n) \\
             & = & \sum_{i=1}^{n}\left[P(A|C_i)P(C_i)\right]
    \end{array}

贝叶斯定理
----------

若\ `C_1, C_2, \dots, C_n`\ 互斥且\ `\bigcup_{i=1}^{n} = S`\ ，则对任意事件\ `A`\ ，有：

.. math::

    \begin{array}
        P(C_j|A) & = & \frac{P(A|C_j)P(C_j)}{P(A|C_1)P(C_1) + P(A|C_2)P(C_2) + \cdots + P(A|C_n)P(C_n)} \\
                 & = & \frac{P(A|C_j)P(C_j)}{\sum_{i=1}^{n}{\left[P(A|C_i)P(C_i)\right]}}
    \end{array}
