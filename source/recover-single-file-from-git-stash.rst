.. meta::
    :tags: git, git-stash

#########################
从git stash中恢复单个文件
#########################

参见StackOverflow的\ `这个问题`__\ 。

__ http://stackoverflow.com/questions/1105253/how-would-i-extract-a-single-file-or-changes-to-a-file-from-a-git-stash

利用\ ``git checkout``\ ：

::

    $ git checkout stash@{0} -- <filename>
