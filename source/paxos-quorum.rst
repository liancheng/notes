.. meta::
    :tags: paxos, quorum, distributed-system, distributed-algorithm

############
Paxos Quorum
############

按照TPTP和Wikipedia的描述，初学者很容易误以为quorum是一轮ballot在投票前就确定下来的一个acceptor集合，实际上并非如此。Proposer只需尽力将proposal发送给尽量多的acceptor，当收到proposal的acceptor集合满足quorum的形成条件时，这些acceptor便成了这轮ballot的quorum。

Quorum的形成条件可以有很多种，只要满足任意两轮ballot的quorum的交集不为空即可。TPTP中只提到了最简单（也最常用）的majority quorum。以下给出两个不同于majority quorum的例子。

分组quorum
==========

9个acceptor，3个一组。在一轮ballot中，

#.  如果一组有2个或2个以上acceptor参与了投票，即视作该组参与了投票；
#.  如果有2组或2组以上参与了投票，则该轮ballot通过。在这个例子中，一轮ballot最少只需要4个acceptor参与投票即可通过，如下所示（\ ``o``\ 表示参与投票的acceptor，\ ``x``\ 表示未参与投票的acceptor）：

::

        o            x            o
       o x          x x          x o
              =>           =>
     x     x      o     o      x     x
    o o   x x    x o   o x    x x   o o

       B1           B2           B3

二维quorum
==========

仍然是9个acceptor，排列成3x3的矩阵。在一轮ballot中，如果投票的acceptor包含至少一个2x2矩阵，则ballot通过。同样，在这个例子中最少只需要4个acceptor即可通过一轮ballot，如下所示：

::

    o o x    x x x    x o o
    o o x => x o o => x o o
    x x x    x o o    x x x

     B1       B2       B3
