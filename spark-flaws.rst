###################
Spark中可能的改进点
###################

Actor
=====

多处使用线程的位置可以改用actor

``JobWaiter``/``EventQueue``\ 这类组合可以用\ ``Future``/Actor实现

DAGScheduler
------------

``DAGScheduler``\ 可以用Actor替代（已完成）

CacheManager
============

CacheManager的block加载逻辑中多线程使用复杂。可以考虑：

#.  所有加载方都对应于一个loader actor
#.  CacheManager本身对应于一个actor，维护\ ``loading: Map[RDDBlockId, Either[ActorRef, Iterator[Any]]]``
#.  所有loader加载前向CacheManager获取加载资格，如果是某block的第一个loader，则获准，加载完毕后，放入CacheManager
#.  如果不是第一个loader，则CacheManager返回正在加载该block的loader的ActorRef，向该ActorRef要完成通知，得到通知后向CacheManager要数据

问题：

#.  如何将各个加载方对应到一个actor？这个actor主体是谁？DriverActor可以承担吗？

SparkEnv
========

使用了thread local storage，可以避免吗？用意何在？是为了保护哪些线程不安全的对象？

Scheduler
=========

DAGScheduler和TaskScheduler职责划分不清晰

TaskScheduler中有一些轮询逻辑，如：

*   ClusterScheduler.start中启动定时任务调用checkSpeculatableTasks()
