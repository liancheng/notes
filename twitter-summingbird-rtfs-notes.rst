##############################
Twitter Summingbird RTFS notes
##############################

:date: 2013/10/02

Twitter官方博客笔记
===================

原文链接： https://blog.twitter.com/2013/streaming-mapreduce-with-summingbird

*   Summingbird是库而不是框架。
*   Twitter此前使用的流处理系统是Storm，批处理系统使用Hadoop/Scalding，整体上类似于Lambda Architecture。但Twitter认为基于Storm实现实时系统相对困难，理由有二：

    *   Recomputation over months of historical logs must be coordinated with Hadoop or streamed through Storm with a custom log loading mechanism

        这里的custom log loading mechanism指的应该是从Hadoop中加载过往数月的日志数据的机制。

    *   Storm is focused on message passing and random-write databases are harder to maintain

        随机写数据库跟Storm有什么关系？

    坦白说这两条都没完全看懂……我觉得最直观的理由应该是同一套处理逻辑需要用Storm和Scalding各自实现一套然后再综合，其中的开发维护开销较大，但文中并没有提到这一点。

*   Summingbird中各种运算都是基于monoid（幺半群）和semigroup（半群）的，换言之应用于数据集之上的二元运算符是符合交换律的，这样一来数据的顺序就无关紧要了。

    Summingbird处理流破缺的关键是否在此？
