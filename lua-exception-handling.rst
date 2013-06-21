######################
Lua exception handling
######################

``lua_longjmp``
    Essentially, it is a single linked list of ``luai_jmpbuf`` (which in most circumstances, is ``jmp_buf``).  Used in ``lua_State->errorJmp``, which is initialized as ``NULL`` in ``preinit_state`` in ``src/lstate.c``.

    .. code-block:: c

        struct lua_longjmp {
          struct lua_longjmp* previous;
          luai_jmpbuf b;
          volatile int status;
        }

    Classic use case (``L`` is a pointer to a ``lua_State`` structure):

    .. code-block:: c

        struct lua_longjmp lj;
        lj.status = LUA_OK;
        lj.previous = L->errorJmp;
        L->errorJmp = &lj;
        LUAI_TRY(L, &lj,
            do_something();
        );
        L->errorJmp = lj.previous;

``LUAI_TRY``
    When used in ANSI C, this macro is defined like this:

    .. code-block:: c

        #define LUAI_TRY(L,c,a) if (setjmp((c)->b) == 0) { a }
