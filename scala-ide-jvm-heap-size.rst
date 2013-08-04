.. meta::
    :tags: eclipse, scala-ide, scala, jvm

#######################
Scala IDE JVM heap size
#######################

https://www.assembla.com/wiki/show/scala-ide/Configuring_Eclipse

Add the following to end of the ``eclipse.ini`` that Eclipse launches with::

    -vmargs
    -server
    -Xms256m
    -Xmx1024m
    -Xss1M
    -XX:MaxPermSize=256m
    -XX:+UseConcMarkSweepGC

Please note that this implies that you should have at least 2G of physical memory on any machine you intend to do Scala IDE for Eclipse development on.

If you are using a recent Oracle JVM you might also find it beneficial to add::

    -XX:+UseConcMarkSweepGC

and if you are using the Oracle 64 bit JVM you should also add::

    -XX:+UseCompressedOops
