####################
Chibi Scheme源码阅读
####################

*   ``sexp_seperators``\ 数组

    与\ ``sexp_is_seperator``\ 配合使用。用于判断给定的ASCII字符是否是token分隔符（相当于R7RS 7.1.1节的\ ``<delimiter>``\ ）。该数组以ASCII值为下标，值为\ ``1``\ 则表示对应的ASCII字符是分隔符，值为\ ``0``\ 则不是。
