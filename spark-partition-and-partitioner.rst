.. meta::
    :tags: spark

###############################
Spark partition and partitioner
###############################

Partition
=========

A parition of an RDD.  Basic loading unit from the cache manager.

Partitioner
===========

Used to define how the elements in a key/value pair ``RDD`` are partitioned by key.  Each key is mapped to a partition ID, which is an ``Int`` within ``0 until numPartitions``

Common partitioners:

*   ``HashPartitioner``

    The default partitioner is ``HashPartitioner``.  Basic partitioning strategy::

        key.hashCode() % numPartitions

*   ``RangePartitioner``

    Partitions sortable records by range into roughly equal ranges.  通过采样来确定range，类似于Terasort。

Related functions
=================

``RDD.coalesce(numPartitions: Int, shuffle: Boolean = false): RDD[T]``
    Return a new RDD that is reduced into ``numPartitions`` partitions.

    把n个partition重新划分成m个partition。多数情况下，task数量是按照一个stage的finalRDD的partition进行划分的（也有例外，例如RDD.take只扫最开始的若干个partition），如果m很小，就会导致整个stage的task数减小并行度降低。这时令shuffle = true，人工插入一个shuffle，将stage切开，可以保证coalesce之前的计算的并行度是n而不是m。

``Partitioner.defaultPartitioner(rdd: RDD[_], others: RDD[_]*)``
    如果\ ``Seq(rdd) ++ others``\ 中任何一个RDD有自定义的partitioner，则返回该partitioner，否则构造一个\ ``HashPartitioner``\ 。
