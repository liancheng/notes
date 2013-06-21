.. meta::
    :tags: sphinx

##############
Sphinx笔记工具
##############

增加一个预处理过程，读取\ ``source``\ 目录下的所有\ ``.rst``\ 文件，取标题和\ ``.. meta::``\ 中\ ``:tags:``\ 的内容，生成供检索用的JSON数据。去除index.html中的TOC，增加JS搜索框，用于搜索笔记的tag。

参考资料：

*   http://www.slideshare.net/doughellmann/better-documentation-through-automation-creating-docutils-sphinx-extensions
*   http://stackoverflow.com/questions/1576340/using-sphinx-to-write-personal-websites-and-blogs
*   http://sphinx-doc.org/templating.html
