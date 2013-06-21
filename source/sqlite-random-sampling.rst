.. meta::
    :tags: sqlite, sql

######################
SQLite random sampling
######################

Select 100 random rows from table ``Table``:

.. code-block:: sql

    SELECT *
    FROM Table
    ORDER BY RANDOM()
    LIMIT 100
