#############################
Typesafe Config library notes
#############################

``ConfigFactory.defaultReference()``
    Obtains default reference configuration, which is currently created by merging all resources ``reference.conf`` found on the classpath and overriding the result with system properties.  The returned reference configuration will already have substitutions resolved.

    Can be used to define default values for all properties.

``ConfigFactory.defaultOverrides()``
    Obtains the default override configuration, which currently consists of system properties.  The returned override configuration will already have substitutions resolved.

``ConfigFactory.load()``
    Loads default configuration, equivalent to ``ConfigFactory.load("application")`` in most cases.

    If the system properties ``config.resource``, ``config.url`` or ``config.file`` are set, then the classpath resource, file or URL specified in those properties will be used rather than the default ``application.{conf,json,properties}`` classpath resources.  These system properties should not be set in code (after all, you can just parse whatever you want manually and then use ``load(Config)``` if you don't want to use ``application.conf``).  The properties are intended for use by the person or script launching the application.

    The loading order:

    #.  Checks to see which configraution file (denoted as *main configuration file* below) to load:

        *   Checks system properties ``config.resource``, ``config.url`` and ``config.file``, if any (but no more than one) of them is set, load configurations from the specified location.
        *   Otherwise, load classpath resource ``application.conf``.

    #.  When loading configurations ``config`` in the main configuration file, the order is::

            ConfigFactory.defaultOverrides(loader)
                         .withFallback(config)
                         .withFallback(defaultReference(loader))

        That is:

        *   Loads the default overrides (i.e., all system properties),
        *   Fallbacks to configurations from the main configuration file (``application.{conf,json,properties}`` in most cases),
        *   Fallbacks to the default reference (i.e., ``reference.{conf,json,properties}``).
