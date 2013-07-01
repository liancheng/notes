.. meta::
    :tags: puppet, ubuntu, plymouth-ready, upstart

##############################################
Puppet workaround with Ubuntu `plymouth-ready`
##############################################

Environment assumption:

*   Ubuntu 12.04
*   Puppet 3.2.2

Related links:

*   Puppet issue: http://projects.puppetlabs.com/issues/21478
*   GitHub push request: https://github.com/puppetlabs/puppet/pull/1731

When running the command ``puppet resource service`` under Ubuntu 12.04, it fails with the following error::

    Error: Could not run: Execution of ‘/sbin/status plymouth-ready’ returned 1: status: Unknown parameter: UPSTART_EVENTS

The reason is that Puppet doesn’t know about Upstart instances natively.  A workaround is adding ``plymouth-ready`` to the exclude list.  Apply `this pull request`__ to ``/usr/lib/ruby/vendor_ruby/puppet/provider/service/init.rb``.

__ https://github.com/puppetlabs/puppet/pull/1731
