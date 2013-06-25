.. meta::
    :tags: spark, scala, sbt

##################
How to build Spark
##################

Install Scala
=============

Download and extract `scala-2.9.3.tgz`__ (other version of Scala is not applicable!) to some place (``$HOME/local/opt`` within this note)::

    $ cd ~/local/opt
    $ sudo wget http://www.scala-lang.org/downloads/distrib/files/scala-2.9.3.tgz
    $ sudo tar xzf scala-2.9.3.tgz
    $ ln -sf scala-2.9.3 scala

__ http://www.scala-lang.org/downloads/distrib/files/scala-2.9.3.tgz

Add environment variable ``$SCALA_HOME`` to ``$HOME/.profile``::

    export SCALA_HOME=$HOME/local/opt/scala

Add ``$SCALA_HOME/bin`` to ``$PATH``::

    export PATH=$PATH:$SCALA_HOME/bin

Run ``scala`` check whether everything is OK::

    $ scala
    Welcome to Scala version 2.9.3 (OpenJDK 64-Bit Server VM, Java 1.7.0_21).
    Type in expressions to have them evaluated.
    Type :help for more information.

    scala>

Setup Spark
===========

Get the source code
-------------------

Clone Spark from GitHub to some local directory (``$HOME/local/src`` within this note)::

    $ cd ~/local/src
    $ git clone https://github.com/mesos/spark/

Setup Spark related environment variable in ``$HOME/.profile``::

    export SPARK_EXAMPLES_JAR=$HOME/local/src/spark/examples/target/scala-2.9.3/spark-examples_2.9.3-0.7.2.jar

.. note:: The ``$SPARK_EXAMPLES_JAR`` environment variable

    ``$SPARK_EXAMPLES_JAR`` is not mentioned in the official documents of Spark, but it's necessary to run examples come with Spark.

Checkout the proper version (optional)
--------------------------------------

Run ``git tag`` to list all the tags and find out the release you need, for example, ``v0.7.2``, then check it out::

    $ cd $SPARK_HOME
    $ git tag
    0.3-scala-2.8
    0.3-scala-2.9
    alpha-0.1
    alpha-0.2
    v0.5.0
    v0.5.1
    v0.5.2
    v0.6.0
    v0.6.0-yarn
    v0.6.1
    v0.6.2
    v0.7.0
    v0.7.0-bizo-1
    v0.7.1
    v0.7.2
    $ git checkout v0.7.2
    Note: checking out 'v0.7.2'.

    You are in 'detached HEAD' state. ...

Compiling
---------

Spark can be conveniently built with ``sbt``.  Although Spark comes with a copy of ``sbt``, it's highly recommended to have a separate installation of ``sbt`` (follow instructions here__).

__ http://www.scala-sbt.org/release/docs/Getting-Started/Setup.html

Now comes the nasty things for us pathetic Chinese developers: fighting with GFW.  Whiling running, ``sbt`` will download everything needed to build Spark from remote repositories, some of which are blocked by the who you know.

If you've got a VPN, then everything's much simpler, just run ``sbt package`` and wait.  Otherwise, find your self a proxy, then follow `this note`__ to setup ``proxychains`` to proxy ``sbt``.  When everything is done, run::

    $ proxychains sbt package

__ proxychains.html

Then have a cup of coffee and wait.

Run the examples
----------------

Run the ``SparkPi`` example::

    $ cd $SPARK_HOME
    $ ./run spark.examples.SparkPi local
