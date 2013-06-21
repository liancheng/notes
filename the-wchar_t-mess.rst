.. meta::
    :tags: wchar_t, unicode, libunistring

####################
The ``wchar_t`` mess
####################

:Source: `GNU libunistring`__

__ http://www.gnu.org/software/libunistring/manual/libunistring.html#The-wchar_005ft-mess

The ISO C and POSIX standard creators made an attempt to fix the first problem mentioned in the previous section.  They introduced

*   a type '``wchat_t``', designed to encapsulate an entire character,
*   a "wide string" type '``wchar_t *``', and
*   functions declared in ``<wctype.h`` that were meant to supplant the ones in ``<ctype.h>``.

Unfortunately, this API and its implementation has numerous problems:

*   On AIX and Windows platforms, ``wchar_t`` is a 16-bit type.  This means that it can never accommodate an entire Unicode character.  Either the ``wchar_t *`` strings are limited to characters in UCS-2 (the "Basic Multilingual Plane" of Unicode), or -- if ``wchar_t *`` strings are encoded in UTF-16 -- a ``wchar_t`` representats only half of a character in the worst case, making the ``<wctype.h>`` functions pointless.
*   On Solaris and FreeBSD, the ``wchar_t`` encoding is locale dependent and undocumented.  This means, if you want to know any property of a ``wchar_t`` character, other than the properties defined by ``<wctype.h>`` -- such as whether it's a dash, currency symbol, paragraph separator, or similar --, you have to convert it to ``char *`` encoding first, by use of the function ``wctomb``.
*   When you read a stream of wide characters, through the functions ``fgetwc`` and ``fgetws``, and when the input stream/title is not in the expected encoding, you have no way to determine the invalid byte sequence and do some corrective action.  If you use these functions, your program becomes "garbage in - more garbage out" or "garbage in abort".

As a consequence, it is better to use multibyte strings, as explained in the previous section, Such multibyte strings can bypass limitations of the ``wchar_t`` type, if you use functions defined in gnulib and libunistring for text processing.  They can also faithfully transport malformed characters that were present in the input without requiring the program to produce garbage or abort.
