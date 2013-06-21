.. meta::
    :tags: encoding, rose, scheme, utf-8

################
ROSE文本编码问题
################

面临的问题：

*   ROSE要支持Unicode

    #.  在ROSE内部采用什么编码更为合适？

        .. compound::

            所谓“内部”，指的是：

            *   ROSE中字符串对象的内部编码
            *   Textual port内部buffer中的编码

            可供选择的编码包括UCS4和UTF-8。优缺点对比如下：

            *   UCS4

                *   优点：每个字符等长，处理方便；\ ``string-length``\ 和\ ``string-ref``\ 是常数复杂度
                *   缺点：浪费空间；由于UTF-8的流行，进行IO时往往还是需要与UTF-8相互转换

            *   UTF-8

                *   优点：与ASCII兼容，较为流行；可直接用基于\ ``char*``\ 的\ ``NUL``\ 结尾C-string表示
                *   缺点：字符不等长，\ ``string-length``\ 和\ ``string-ref``\ 为线性复杂度

    #.  采用第三方库还是自行编写代码完成Unicode操作？

        可供选择的第三方库包括libunistring、glib、ICU、libiconv。其中ICU的内部编码表示是UCS2，不能表示全部codepoint，可能无法满足需要（尚需确认）；libiconv则尽可用于文本块的编码转换，无法进行其他精细操作；glib本身过于庞大，可能有碍于嵌入式应用和可移植性。

    #.  需要哪些Unicode操作？

        参考GLib的Unicode Manipulation API和Character Set Conversion API。

    #.  ROSE的字符类型如何表示？

        采用UCS4配合tagged-pointer，native字节序。决策原因：

        *   Unicode标准含有17个位面，每个位面容纳\ `2^{16}`\ 个元素，因此仅需21个bit即可表示Unicode标准中的所有codepoint；
        *   ROSE当前的tagged-pointer仅需3个bit来存储额外的tag信息，加上21个bit的codepoint信息，可以容纳于最小32位的\ ``rsexp``\ 类型内。

    #.  Port体系怎么设计？

        .. compound::

            Port的类型有如下三个维度：

            *   Binary/textual
            *   Input/output
            *   File/string/bytevector

            其中textual port配有transcoder，负责处理字符编码和换行符类型。

            .. csv-table:: Port操作
                :header: 操作类型, B/I, B/O, T/I, T/O

                ``open``, ``open-binary-input-file`` ``open-input-bytevector``, ``open-binary-output-file`` ``open-output-bytevector``, ``open-input-file`` ``open-input-string``, ``open-output-file`` ``open-output-string``
                ``close``, ``close-port`` ``close-input-port``, ``close-port`` ``close-output-port``, ``close-port`` ``close-input-port``, ``close-port`` ``close-output-port``
                ``read-unit``, ``read-u8``, --, ``read-char``, --
                ``peek-unit``, ``peek-u8``, --, ``peek-u8``, --
                ``unit-ready?``, ``u8-ready?``, --, ``char-ready?``, --
                ``write-unit``, --, ``write-u8``, --, ``write-char``
                ``write-sequence``, --, ``write-bytevector`` ``write-partial-bytevector``, --, --
                ``write-object``, --, --, --, ``write`` ``display`` ``write-simple`` ``display-simple``
                ``get-line-number``, --, --, --, ``get-line-number``

        由此可将Port体系分为三层：

        *   第一层为对外API，实现R7RS Port的各种语义
        *   第二层分为两部分：
          
            *   Port API，封装binary/textual、input/output语义，包括以下API接口：

                *   ``open``
                *   ``close_read``
                *   ``close_write``
                *   ``read_unit``
                *   ``peek_unit``
                *   ``unit_ready_p``
                *   ``write_unit``
                *   ``write_sequence``
                *   ``get_line_number``

            *   Transcoder API，分为Codec和Transcoder两部分，处理字符集和换行符问题。

        *   第三层为Stream API，利用\ ``FILE*``\ 封装file/string/bytevector语义
