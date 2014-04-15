##########################
How to deploy my own blog?
##########################

Crap... After being confused multiple times, I decide to write it down. 

#.  Clone the repository::

        git clone git@github.com:liancheng/blog.liancheng.info.git

#.  Install Jekyll::

        sudo gem install jekyll

#.  Install docutils::

        sudo pip install docutils

#.  Synchronize submodule (``jekyll-rst``)::

        git submodule init
        git submodule update

#.  Install ``kramdown``::

        sudo gem install kramdown

#.  Install ``RbST``::

        sudo gem install RbST

#.  Make sure Python default encoding set to 'UTF-8':

    -   Run the following code to locate Python user site directory:

        .. code-block:: python
        
            >>> import site
            >>> print site.USER_SITE

    -   Create the user site directory if needed.

    -   Create file ``usercustomized.py``::

        .. code-block:: python
        
            import sys
            sys.setdefaultencoding('utf-8')

#.  Build the blog::

        jekyll build
