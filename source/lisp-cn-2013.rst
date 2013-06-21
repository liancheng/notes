.. meta::
    :tags: common-lisp, clojure, lisp

##########################
中国Lisp爱好者聚会（2013）
##########################

:date: 2013-03-16

小议Clojure与其它Lisp的异同
===========================

:author: 帝归（胥帝）

* Lisp-1 v.s. Lisp-2

  * Lisp-2: Common Lisp
  * Lisp-1: Scheme, Elisp, Clojure

* OO support of Clojure: ``defmulti``/Java

* FP support of Clojure: Immutable

* Concurrency: STM

Web programming with Clojure
============================

:author: shenfeng
:github: http://github.com/shenfeng

without framework, better and more fun

Clojure http abstraction: Ring

* Request/response map
* Handler (servlet)
* Middleware (filter)
* Adapter (converts HTTP req/resp to/from maps)

Prolog and the birth of Erlang
==============================

:author: Han Kai
:github: http://isaachan.github.com
:company: ThoughtWorks

Prolog: designed by Alain Colmerauer in 1972, influenced Erlang and OZ, logic programming.

Compound term:

- rainy(beijing)
- person(Name, 26)

List:

    [H|T]

String:

    "hello"

Rule (if ``Body`` is true, then ``Head`` is true):

    Head :- Body

Unification (pattern matching?)
