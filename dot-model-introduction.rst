###########
DOT模型介绍
###########

:日期: 2013/09/27
:主讲: 骆涛

Scale-up
    提高单个计算单元的计算能力。分布式情况下要减小通讯，节点间往往配备InfinitiBand

    *   经典计算模型：BSP、LogP
    *   经典编程模型：MPI

Scale-out
    增加计算单元。添加机器、添加存储资源。

    *   经典计算模型：无
    *   经典编程模型：MapReduce、Dryad

DOT模型
    DOT分别是三层

    *   D：数据层，例如HDFS
    *   O：操作层，例如Map
    *   T：转换层，例如Reduce

    DOT块的组合：

    *   由多个独立的基本DOT块组成
    *   约束条件

        *   O层不能相互通讯
        *   T层不能相互通讯
        *   中间数据只能由O层向T层发送

`An SQL-to-MapReduce Translator`__

__ http://ysmart.cse.ohio-state.edu/
