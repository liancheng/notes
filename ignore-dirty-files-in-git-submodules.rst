.. meta::
    :tags: git, git-submodule, gitignore

#########################
忽略Git submodule中的文件
#########################

http://stackoverflow.com/questions/5127178/gitignore-files-added-inside-git-submodules

.. code-block:: ini

    [submodule "path/to/submodule"]
        path = path/to/submodule
        url = http://github.com/username/repo.git
        ignore = untracked # <==
