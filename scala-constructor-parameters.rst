#################
Scala构造函数参数
#################

.. csv-table::
    :header: Scala field, Field, Getter, Setter

    ``val name``,               private ``name``,   public ``name``,    n/a
    ``var name``,               private ``name``,   public ``name``,    public ``name_=``
    ``@BeanProperty val name``, private ``name``,   public ``getName``, n/a
    ``@BeanProperty var name``, private ``name``,   public ``getName``, public ``setName``
    ``private val name``,       private ``name``,   n/a,                n/a
    ``private var name``,       private ``name``,   n/a,                private ``name_=``
    ``private[this] val name``, n/a,                n/a,                n/a
    ``private[this] var name``, n/a,                n/a,                n/a
