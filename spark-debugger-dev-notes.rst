########################
Spark debugger dev notes
########################

Ported

*   Most features in ``EventLogReader.scala``

    ``EventLogReader`` is the key class of the Spark debugger.  It reads recorded events from the event log (an ``ObjectInputStream``), and provides functions to investigate and manipulate the RDD graph.

    Not ported:

    *   ``visualizeRDDs``

*   ``EventLogWriter.scala``
*   ``EventReporter.scala``
*   ``EventLogging.scala``

Configurations
==============

*   ``SPARK_MASTER_HOST``/``spark.master.host``: String
*   ``SPARK_MASTER_PORT``/``spark.master.port``: Int, default to 7077
*   ``spark.arthur.enabled``: Boolean, default to ``true``
*   ``spark.arthur.checksum``: Boolean, default to ``true``
*   ``SPARK_ARTHUR_LOGPATH``: String
