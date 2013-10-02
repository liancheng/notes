######################
Hadoop map task number
######################

Given a job, how does Hadoop determine how many map tasks to spawn?  Take Hadoop 1.1.2 WordCount as an example, this note describes the this process.

When running a WordCount job with ``SequenceFileInputFormat``, the call chain is:

#.  ``org.apache.hadoop.mapred.WordCount.run``

    .. code-block:: java

        JobClient.runJob(conf);

#.  ``org.apache.hadoop.mapred.JobClient.runJob``

    .. code-block:: java

        RunningJob rj = jc.submitJob(job);

#.  ``org.apache.hadoop.mapred.JobClient.submitJob``

    .. code-block:: java

        return submitJobInternal(job);

#.  ``org.apache.hadoop.mapred.JobClient.submitJobInternal``

    .. code-block:: java

        int maps = writeSplits(context, submitJobDir);

#.  ``org.apache.hadoop.mapred.JobClient.writeSplits``

    So map task number is determined by the split number.  The following logic chooses between ``writeNewSplits`` and ``writeOldSplits`` according to the ``mapred.mapper.new-api`` property.  Let's take ``writeOldSplits``.

    .. code-block:: java

        if (jConf.getUseNewMapper()) {
          maps = writeNewSplits(job, jobSubmitDir);
        } else {
          maps = writeOldSplits(jConf, jobSubmitDir);
        }

#.  ``org.apache.hadoop.mapred.JobClient.writeOldSplits``

    WordCount uses the default ``InputFormat``, namely ``TextInputFormat``, which is not splittable when compression is enabled.  When running WordCount with HiBench, ``SequenceFileInputFormat`` is used, which is splittable.  Let's take the latter case.

    The second argument passed to ``getSplits`` is the value of the ``mapred.map.tasks`` property, which defaults to 1.

    .. code-block:: java

        org.apache.hadoop.mapred.InputSplit[] splits =
        job.getInputFormat().getSplits(job, job.getNumMapTasks());

#.  ``org.apache.hadoop.mapred.FileInputFormat.getSplits``

    ``SequenceFileInputFormat.getSplits`` is inherited from ``FileInputFormat.getSplits``.

    *   Lists all input files:

        .. code-block:: java

            FileStatus[] files = listStatus(job);

    *   Computes the total size of all input files:

        .. code-block:: java

            // Save the number of input files in the job-conf
            job.setLong(NUM_INPUT_FILES, files.length);
            long totalSize = 0;                           // compute total size
            for (FileStatus file: files) {                // check we have valid files
              if (file.isDir()) {
                throw new IOException("Not a file: "+ file.getPath());
              }
              totalSize += file.getLen();
            }

    *   
