.. meta::
    :tags: spark, scala

################
Spark RTFS notes
################

Based on v0.7.3

Main entry: ``SparkContext``

Deployment module
=================

Meaning of several ``RemoteClientLifeCycleEvent`` case classes:

*   ``RemoteClientShutdown``

    The underlying remote connection is *going to be* shutdown.

*   ``RemoteClientDisconnected``

    The underlying remote connection is already shutdown.

Start/stop scripts
==================

.. note:: Spark home directory 

    The Spark home direcotry, or simply the Spark home, is the directory which ``bin/start-all.sh`` is relative to.

The ``spark-config.sh`` script
------------------------------

The ``spark-config.sh`` script sets:

*   ``$SPARK_PREFIX`` to the Spark home directory
*   ``$SPARK_HOME`` to ``$SPARK_PREFIX``
*   ``$SPARK_CONF_DIR`` to ``${SPARK_HOME}/conf``

The ``start-all.sh`` script
---------------------------

#.  Sources ``spark-config.sh``
#.  Runs ``start-master.sh``
#.  RUns ``start-slaves.sh``

The ``start-master.sh`` script
------------------------------

#.  Sources ``spark-config.sh``
#.  Sources ``${SPARK_CONF_DIR}/spark-env.sh`` if there is one
#.  Sets master ip and port:

    *   Sets ``$SPARK_MASTER_PORT`` to 7077 if not otherwise specified
    *   Sets ``$SPARK_MASTER_IP`` to the output of the ``hostname`` command if not otherwise specified
    *   Sets ``$SPARK_MASTER_WEBUI_PORT`` to 8080 if not otherwise specified

#.  Sets ``$SPARK_PUBLIC_DNS`` (seems that it's not used elsewhere yet)
#.  Runs ``spark-daemon.sh`` to start Spark master

The ``spark-daemon.sh`` script
------------------------------

#.  Sources ``${SPARK_CONF_DIR}/spark-env.sh`` if there is one

The ``spark-class`` script
--------------------------

``$SPARK_PRINT_LAUNCH_COMMAND``
    As the name suggests: print launch command

RDD
===

The abstraction of the Resilient Distributed Dataset.

*   cache
*   compute
*   iterator
*   partition
*   preferedLocation

Partition and Partitioner
=========================

Partitioner
    Used to define how the elements in a key/value pair ``RDD`` are partitioned by key.  Each key is mapped to a partition ID, which is an ``Int`` within ``0 until numPartitions``

    Common partitioners:

    *   ``HashPartitioner``

        The default partitioner is ``HashPartitioner``.  Basic partitioning strategy::

            key.hashCode() % numPartitions

    *   ``RangePartitioner``

        Partitions sortable records by range into roughly equal ranges.

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

    StandaloneSchedulerBackend -> SchedulerBackend
    CoarseMesosSchedulerBackend -> StandaloneSchedulerBackend
    SparkDeploySchedulerBackend -> StandaloneSchedulerBackend

    MesosSchedulerBackend -> SchedulerBackend

    SchedulerBackend -> ClusterScheduler [
        arrowhead = odiamond
        headlabel = "1..1"
        taillabel = "1..1"
    ]
