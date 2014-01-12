#############
Spark shuffle
#############

``ShuffleRDD.compute``
    ``ShuffleRDD``\ 的dependency类型是\ ``ShuffleDependency``\ 。首先取该dependency的\ ``shuffleId``\ ，然后调用\ ``ShuffleFetcher.fetch``\ 。

``ShuffleFetcher.fetch``
    完整函数签名为：

    .. code-block:: scala
    
        ShuffleFetcher.fetch(
            shuffleId: Int,
            reduceId: Int,
            metrics: TaskMetrics,
            serializer: Serializer): Iterator[T]

    该函数的语义应该是：返回一个\ ``Iterator[T]``\ ，指向ID为\ ``shuffleId``\ 的这次shuffle中split索引为\ ``reduceId``\ 的shuffle output中的所有元素。

    首先计算所有map output tracker上第\ ``shuffleId``\ 号shuffle中属于第\ ``reduceId``\ 分片的数据各有多少：

    .. code-block:: scala
    
        val statuses = SparkEnv.get.mapOutputTracker.getServerStatuses(shuffleId, reduceId)

    .. todo:: Map output tracker是个啥？

    数组\ ``statuses``\ 的元素类型是\ ``(BlockManagerId, Long)``\ ，其中表示某个\ ``BlockManager``\ 中所存的shuffle分片的大小。
