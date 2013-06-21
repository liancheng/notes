.. meta::
    :tags: emacs, org-mode, date, timestamp

######################
Org-mode date and time
######################

Insert/modify timestamp
=======================

 ``C-c .``
     Prompt for a date and insert a corresponding timestamp.

     When the cursor is at an existing timestamp in the buffer, the command is used to modify this timestamp instead of inserting a new one.

     When used twice in succession, a time range is inserted

 ``C-c !``
     Like ``C-c .``, but insert an inactive timestamp that will not cause an agenda entry.
