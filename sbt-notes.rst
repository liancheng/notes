#########
SBT notes
#########

SBT ends up with an immutable map describing the build.

A build definition defines a list of ``Setting[T]``, where a ``Setting[T]`` is a transformation affecting sbt's map of key-value pairs and ``T`` is the type of each value.

.. compound::

    ``build.sbt`` defines a ``Seq[Setting[_]]``, separated by blank lines.  It means that this code

    .. code-block:: scala

        name := "hello"

        version := "1.0"

        scalaVersion := "2.9.2"

    is equivalent to

    .. code-block:: scala

        Seq(
          name := "hello",
          version := "1.0",
          scalaVersion := "2.9.2"
        )

Expressions like ``key := value`` are key-value ``Setting``\ s.  The ``name``, ``version`` and ``scalaVersion`` in the above example, are instances of ``SettingKey[T]``, ``TaskKey[T]``, or ``InputKey[T]``, where ``T`` is the expected value type.

The ``:=`` method of key objects returns a ``Setting``.
