###################################
Kraft, the Akka RAFT implementation
###################################

Design issues remain in question:

#.  Initial membership

Issues about Akka 2.2:

#.  ``Timeout.never`` is removed, and ``Timeout`` objects can only be constructed with ``FiniteDuration``.  Then how to wait indefinitely when using the ``ask`` pattern?

    I think Akka added these restrictions because waiting indefinitely when ``ask``\ ing an actor is an improper behaviour, since the target actor may never response, either because the request/response message is not successfully delivered or the target actor failed to send the response.
