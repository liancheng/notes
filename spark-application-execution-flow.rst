.. meta::
    :tags: spark

################################
Spark application execution flow
################################

Takes ``SparkPi`` as an example, run ``SparkPi`` under standalone mode:

#.  Create ``SparkContext`` instance.

    *   Create and start ``TaskScheduler`` instance

        The concrete type of the ``TaskScheduler`` is based on the master address.  In this example, the Spark master address should be something like ``spark://host:7077``, and the concrete type should be ``ClusterScheduler``, whose backend is ``SparkDeploySchedulerBackend``.

#.  Start the ``SparkPi`` task with ``reduce``:

    .. code-block:: scala

        val count = spark.parallelize(1 to n, slices).map { i =>
          val x = random * 2 - 1
          val y = random * 2 - 1
          if (x * x + y * y < 1) 1 else 0
        }.reduce(_ + _)                     // <---

#.  Call ``SparkContext.runJob`` within ``RDD.reduce``:

    .. code-block:: scala

        sc.runJob(this, reducePartition, mergeResult)

#.  ``DAGScheduler.runJob``

    Prepare a ``JobSubmitted`` event objet and enqueue it into the event queue.

    .. code-block:: scala

        val (toSubmit: JobSubmitted, waiter: JobWaiter[_]) =
            prepareJob(finalRDD, func, partitions, callSite, allowLocal, resultHandler, properties)

        eventQueue.put(toSubmit)

#.  ``DAGScheduler.run``

    ``DAGScheduler.start`` starts a thread to run ``DAGScheduler.run``, polling the event queue then ``processEvent``.

#.  ``DAGScheduler.processEvent``

    The ``JobSubmitted`` case branch, ``submitStage``

#.  ``DAGScheduler.submitStage``

#.  ``DAGScheduler.submitMissingTasks``

    There're two kinds of tasks: ``ShuffleMapTask`` and ``ResultTask``

#.  ``TaskScheduler.submitTasks``

    ``ClusterScheduler.submitTasks``

#.  ``ClusterTaskSetManager``
