.. meta::
    :tags: virtualbox, vm

###############################
Hide VirtualBox guest VM window
###############################

If you're running a Linux VM as a server without X, and only access it via SSH, then the guest VM window would become useless and annoying.  To run the VM without the guest VM window, use ``VBoxHeadless``::

    $ VBoxHeadless --startvm <vm-name|uuid>

(Note: concise VM names would be helpful, or you may want to run this command via scripts.)
