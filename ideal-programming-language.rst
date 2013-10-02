##############
理想的编程语言
##############

:date: 2013/10/02

应具备以下特点：

#.  可编译执行亦可解释执行
#.  纯函数式，无副作用，IO通过monad实现
#.  在语言及虚拟机层面（甚至操作系统层面）支持actor模型，以actor为单位进行GC，将GC开销均摊开来，实现软实时

    .. note::

        Actor的创建和消息收发仍然是副作用，这点与纯函数式的要求是相背的。能否利用monad将actor的创建及消息收发抽象出来，还有待考证。

#.  位置透明
#.  默认求值顺序为strict，但支持lazy语义
#.  支持HM类型推导，具备类似于Haskell和Scala的类型体系，支持type class，用以实现monad邓高级抽象结构
#.  类型系统只存在于编译期，避免运行时类型信息
#.  摒弃Haskell和Python的缩进语法，简化parser实现
#.  为了避免dangling expression，可能保留分号等表达式分隔符
#.  支持hygienic macro
#.  First class continuation？First class delimited continuation？
