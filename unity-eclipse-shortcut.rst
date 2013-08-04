.. meta::
    :tags: unity, ubuntu, eclipse

######################
Unity Eclipse shortcut
######################

http://askubuntu.com/questions/80013/how-to-pin-eclipse-to-the-unity-launcher

First, create a ``.desktop`` file to eclipse::

    $ vim ~/.local/share/applications/eclipse.desktop

Then, paste this inside (dont forget to edit Exec and Icon values)::

    [Desktop Entry]
    Type=Application
    Name=Eclipse
    Comment=Eclipse Integrated Development Environment
    Icon=** something like /opt/eclipse/icon.xpm **
    Exec= ** something like /opt/eclipse/eclipse **
    Terminal=false
    Categories=Development;IDE;Java;
    StartupWMClass=Eclipse

Finally drop ``eclipse.desktop`` to launcher.
