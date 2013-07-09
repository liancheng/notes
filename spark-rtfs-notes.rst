.. meta::
    :tags: spark, scala

################
Spark RTFS notes
################

Main entry: ``SparkContext``

Meaning of several ``RemoteClientLifeCycleEvent`` case classes:

*   ``RemoteClientShutdown``

    The underlying remote connection is *going to be* shutdown.

*   ``RemoteClientDisconnected``

    The underlying remote connection is already shutdown.
