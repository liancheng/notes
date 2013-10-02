#####################
Spark Config proposal
#####################

Motivation
==========

By greping ``System.getenv`` and ``System.getProperties`` in the source tree, we can easily find out that Spark now adopts as many as 99 Java properties and 39 environment variables for various configurations.  It would be great to manage them in a unified and convenient way.

Current state of Spark's configuration management:

*   Propertie name and environment variable name are chosen in a rather ad-hoc way, most of them are undocumented
*   Default values (if any) are hard-coded and undocumented
*   Verbose code for checking ``null``\ s or ``None``\ s
*   Verbose code for type casting (``toInt``, ``toBoolean``, ...)

Appendix A. Java properties
===========================

::

    java.io.tmpdir
    java.vendor
    master.ui.port
    os.arch
    os.name
    path.separator
    QUEUE
    spark.akka.askTimeout
    spark.akka.batchSize
    spark.akka.frameSize
    spark.akka.logLifecycleEvents
    spark.akka.num.retries
    spark.akka.retry.wait
    spark.akka.threads
    spark.akka.timeout
    spark.akka.writeTimeout
    spark.arthur.checksum
    spark.arthur.enabled
    spark.arthur.logPath
    spark.broadcast.compress
    spark.buffer.size
    spark.cache.class
    spark.cleaner.ttl
    spark.closure.serializer
    spark.core.connection.connect.threads.keepalive
    spark.core.connection.connect.threads.max
    spark.core.connection.connect.threads.min
    spark.core.connection.handler.threads.keepalive
    spark.core.connection.handler.threads.max
    spark.core.connection.handler.threads.min
    spark.core.connection.io.threads.keepalive
    spark.core.connection.io.threads.max
    spark.core.connection.io.threads.min
    spark.cores.max
    spark.dead.worker.persistence
    spark.default.parallelism
    spark.deploy.retainedApplications
    spark.deploy.spreadOut
    spark.diskStore.subDirectories
    spark.driver.host
    spark.driver.port
    spark.executor.memory
    spark.executor.uri
    spark.home
    spark.hostPort
    spark.httpBroadcast.uri
    spark.io.compression.snappy.block.size
    spark.kryo.referenceTracking
    spark.kryo.registrator
    spark.kryoserializer.buffer.mb
    spark.local.dir
    spark.locality.wait
    spark.locality.wait.node
    spark.locality.wait.process
    spark.locality.wait.rack
    spark.logging.exceptionPrintInterval
    spark.master.host
    spark.master.port
    spark.mesos.coarse
    spark.mesos.extra.cores
    spark.metrics.conf
    spark.rdd.compress
    spark.reducer.maxMbInFlight
    spark.repl.classdir
    spark.repl.class.uri
    spark.scheduler.allocation.file
    spark.scheduler.mode
    spark.scheduler.revive.interval
    spark.serializer
    spark.shuffle.compress
    spark.shuffle.copier.threads
    spark.shuffle.file.buffer.kb
    spark.shuffle.netty.connect.timeout
    spark.shuffle.sender.port
    spark.shuffle.use.netty
    spark.speculation
    spark.speculation.interval
    spark.speculation.multiplier
    spark.speculation.quantile
    spark.starvation.timeout
    spark.storage.blockManagerSlaveTimeoutMs
    spark.storage.blockManagerTimeoutIntervalMs
    spark.storage.memoryFraction
    spark.streaming.blockInterval
    spark.streaming.clock
    spark.streaming.concurrentJobs
    spark.streaming.manualClock.jump
    spark.task.cpus
    spark.task.maxFailures
    spark.test.disableBlockManagerHeartBeat
    spark.test.useCompressedOops
    spark.ui.port
    spark.ui.retained_stages
    spark.worker.timeout
    spark.yarn.applicationMaster.waitTries
    spark.yarn.ApplicationMaster.waitTries
    SPARK_YARN_MODE
    user.name
    worker.ui.port

Appendix B. Environment variables
=================================

::

    ADD_JARS
    APPLICATION_WEB_PROXY_BASE
    AWS_ACCESS_KEY_ID
    AWS_SECRET_ACCESS_KEY
    JAVA_HOME
    LOCAL_DIRS
    MASTER
    MESOS_NATIVE_LIBRARY
    SPARK_DEBUG_REPL
    SPARK_EXAMPLES_JAR
    SPARK_EXECUTOR_URI
    SPARK_HOME
    SPARK_JAR
    SPARK_LOCAL_IP
    SPARK_LOG4J_CONF
    SPARK_LOG_DIR
    SPARK_MASTER_HOST
    SPARK_MASTER_PORT
    SPARK_MASTER_WEBUI_PORT
    SPARK_MEM
    SPARK_PUBLIC_DNS
    SPARK_WORKER_CORES
    SPARK_WORKER_DIR
    SPARK_WORKER_MEMORY
    SPARK_WORKER_PORT
    SPARK_WORKER_WEBUI_PORT
    SPARK_YARN_JAR_PATH
    SPARK_YARN_JAR_SIZE
    SPARK_YARN_JAR_TIMESTAMP
    SPARK_YARN_LOG4J_PATH
    SPARK_YARN_LOG4J_SIZE
    SPARK_YARN_LOG4J_TIMESTAMP
    SPARK_YARN_MODE
    SPARK_YARN_USER_ENV
    SPARK_YARN_USERJAR_PATH
    SPARK_YARN_USERJAR_SIZE
    SPARK_YARN_USERJAR_TIMESTAMP
    TEST_VAR
    YARN_LOCAL_DIRS
