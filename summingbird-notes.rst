#################
Summingbird notes
#################

In Storm that that function call might populate a log stream, or another realtime queue that a further Summingbird topology could pull in as a ``Source``.

代码风格很好，工程上井然有序。测试代码风格不太统一。

``Producer`` API

*   实现的方法基本跟monad要求一致：A co-Relational Model of Data for Large Shared Data Banks
*   ``Producer.write``\ 相当于\ ``foreach``
*   跟\ ``RDD``\ 很类似，但紧凑许多。
*   没有partition。没有BlockManager层。Summingbird作为库，不需要这两个抽象。相关细节由Platform搞定。

Summingbird要想扩展新的\ ``Producer``\ 类型会比较麻烦。有若干处代码硬编码了所有\ ``Producer``\ 的类型。如\ ``Producer.dependenciesOf``\ 。此处其实可以很容易地通过给\ ``Producer``\ 增加一个类似于\ ``RDD.dependencies``\ 的方法来解耦，但Summingbird选择了更FP同时也更不方便扩展的做法。

``Producer.writer``\ 相当于\ ``foreach``\ 。

由于遵循FP范式，Summingbird的单元测试可以直接使用ScalaCheck，只需描述被测类型所应遵循的定律，具体测使用例又ScalaCheck自动生成。示例：

*   ``BatcherLaws``\ ：以声明式语法描述了五条定律
*   ``StormLaws``\ ：相对不那么FP，因此测试代码要复杂许多
