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
