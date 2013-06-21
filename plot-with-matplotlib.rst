####################
``matplotlib``\ 绘图
####################

示例代码
========

.. code-block:: python

    import matplotlib.pyplot as plt
    plt.plot([1, 2, 3, 4], [1, 4, 9, 16], 'ro')
    plt.axis(0, 6, 0, 20)

控制曲线样式
============

通过控制\ ``plot``\ 函数的\ ``fmt``\ 参数。\ ``fmt``\ 分为颜色和样式两部分，例如：

*   ``b-``\ 是蓝色实线：\ ``b``\ 表示蓝色，\ ``-``\ 表示实线
*   ``ro``\ 是红色圆圈：\ ``r``\ 表示红色，\ ``o``\ 表示圆圈
*   ``kx``\ 是黑色叉：\ ``k``\ 表示黑色，\ ``x``\ 表示叉

控制数轴范围
============

.. code-block:: python

    plt.axis(0, 6, 0, 20) # xmin, xmax, ymin, ymax

绘制函数图形
============

.. code-block:: python

    import numpy as np
    import matplotlib.pyplot as plt

    # 0至5，每0.2一个点
    t = np.arange(0., 5., 0.2)

    # 同时绘制线性函数、平方函数、立方函数
    plt.plot(t, t,    'r--',
             t, t**2, 'bs',
             t, t**3, 'g^')

    plt.show()
