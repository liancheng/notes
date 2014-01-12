.. meta::
    :tags: spark, scheduler, executor

############################
Spark scheduler and executor
############################

DAGScheduler
============

#.  DAGScheduler.runJob中，func和resultHandler的区别是什么？

    func用于处理单个partition中的每个元素，resultHandler用于处理每一个partition对应的task执行完毕后得到的TaskResult。

    func是在各个Executor上执行的，resultHandler是在driver处执行的。

Scheduler
=========

.. digraph:: Scheduler 

    fontname = "WenQuanYi Zen Hei Mono"
    fontsize = 8
    rankdir = BT
    ranksep = 0.7

    node [
        shape = record
        fontname = "WenQuanYi Zen Hei Mono"
        fontsize = 8
    ]

    edge [
        arrowhead = empty
        fontname = "WenQuanYi Zen Hei Mono"
        fontsize = 8
    ]

    TaskScheduler -> SparkContext [
        arrowhead = odiamond
    ]

    ClusterScheduler -> TaskScheduler
    YarnClusterScheduler -> ClusterScheduler

    LocalScheduler -> TaskScheduler

    DAGScheduler [
        label = "{DAGScheduler|- eventQueue: LinkedBlockingQueue\l|- processEvent()\l}"
    ]

    TaskSchedulerListener [
        label = "{TaskSchedulerListener|+ taskStarted()\l+ taskEnded()\l+ executorGained()\l+ executorLost()\l+ taskSetFailed()\l}"
    ]

    TaskScheduler [
        label = "{TaskScheduler|+ rootPool\l+ schedulingMode\l|+ start()\l+ stop()\l+ postStartHook()\l+ submitTask()\l+ setListener\l+ defaultParallelism()\l}"
    ]

    DAGScheduler -> TaskSchedulerListener

    TaskSchedulerListener -> TaskScheduler [
        arrowhead = odiamond
        headlabel = "1..1"
        taillabel = "1..1"
    ]

    SchedulerBackend [
        label = "{SchedulerBackend|+ start()\l+ stop()\l+ reviveOffers()\l+ defaultParallelism()}"
    ]

    driverActor -> StandaloneSchedulerBackend [
        arrowhead = diamond
    ]

    StandaloneSchedulerBackend -> SchedulerBackend
    CoarseMesosSchedulerBackend -> StandaloneSchedulerBackend
    SparkDeploySchedulerBackend -> StandaloneSchedulerBackend

    MesosSchedulerBackend -> SchedulerBackend

    SchedulerBackend -> ClusterScheduler [
        arrowhead = odiamond
        headlabel = "1..1"
        taillabel = "1..1"
    ]

Executor
========

.. digraph:: Executor

    fontname = "WenQuanYi Zen Hei Mono"
    fontsize = 8
    rankdir = BT
    ranksep = 0.7

    node [
        shape = record
        fontname = "WenQuanYi Zen Hei Mono"
        fontsize = 8
    ]

    edge [
        arrowhead = empty
        fontname = "WenQuanYi Zen Hei Mono"
        fontsize = 8
    ]

    ExecutorBackend [
        label = "{ExecutorBackend|+ statusUpdate()\l}"
    ]

    MesosExecutorBackend -> ExecutorBackend
    MesosExecutorBackend -> "org.apache.mesos.Executor"

    StandaloneExecutorBackend -> ExecutorBackend
    StandaloneExecutorBackend -> Actor

    Executor -> StandaloneExecutorBackend [
        arrowhead = odiamond
    ]

    driver -> StandaloneExecutorBackend [
        arrowhead = odiamond
    ]

Misc
====

``ClusterTaskSetManager.checkSpeculatableTasks``\ 用于筛查运行时间过长的任务，它们可能成为straggler。
