.. meta::
    :tags: algorithm, kmp

#################
The KMP Algorithm
#################

String matching with finite automata
====================================

A finite automaton `M` induces a function `\phi`, called the *final-state function*, from `\Sigma^*` to `Q` such that `\phi(w)` is the state `M` ends up in after scanning the string `w`.

.. math::
    :label: final-state-function

    \begin{eqnarray}
     \phi(\epsilon) & = & q_0,\\
     \phi(wa)       & = & \delta(\phi(w),a) \quad \text{for } w \in \Sigma^*, a \in \Sigma
    \end{eqnarray}

Suffix function `\sigma(x)` is the length of the longest prefix of `P` (the pattern string) that is also a suffix of `x`.

.. math::
    :label: suffix-function

    \sigma(x)=max\{k : P_k \sqsupset x\}

The string-matching automaton that corresponds to a given pattern `P[1..m]` as follows:

*   The state set `Q` is `\{0, 1, \dots, m\}`.  The start state `q_0` is state `0`, and state `m` is the only accepting state.
*   The transition function `\delta` is defined by the following equation, for any state `q` and character `a`:

    .. math::

        \delta(q, a) = \sigma(P_q a) = \phi(P_q a)

    .. admonition:: Explaination
        :class: alert alert-info

        Under the following conditions:
        
        #.  The current state of `M` is `q`, which implies:

            *   `q` characters have been matched
            *   Let `T_i` be the text that have already been searched, we have `P_q \sqsupset T_i`

        #.  The next character is `a`

        Then the next state `\delta(q, a)` is `\sigma(P_q a)`

Pseudo-code for the DFA construction:

    |   `m = P.length`
    |   `\text{for each } q \in \{0, \dots, m - 1\}`
    |       `\text{for each character } a \in \Sigma`
    |           `k = q + 1`
    |           `\text{while } P_q a \not\sqsupset P_k`
    |               `k = k - 1`
    |           `\delta (q, a) = k`
    |   `\text{return } \delta`

.. note::
    :class: alert alert-info

    The pseudo-code above is a bit different from the CLRS book.  Since `m` is the only accepting state, there's no need to consider `m` while constructing the DFA.

    In the inner most loop starts from line 5, if `k` ends up with `q + 1`, it means that `a` is exactly the `q+1`-th character in the pattern.

KMP
===

The KMP algorithm avoids computing the transition function `\delta` altogether, and its matching time is `\Theta(n)` using just an auxiliary function `\pi`, which we precompute from the pattern in time `\Theta(m)` and store in an array `\pi[1..m]`.  The array `\pi` allows us to compute the transition function `\delta` efficiently (in an amortized sense) "on the fly" as needed.  Loosely speaking, for any state `q = 0, 1, \dots, m` and any character `a \in \Sigma` the value `\pi[q]` contains the information we need to compute `\delta(q, a)` but that does not depend on `a`.  Since the array `\pi` has only `m` entries, whereas `\delta` has `\Theta(m |\Sigma|)` entries, we save the factor of `|\Sigma|` in the preprocessing time by computing `\pi` rather than `\delta`.

Given a pattern `P[1..m]`, the *prefix function* for the pattern `P` is the function `\pi:\{1, 2, \dots, m\} \rightarrow \{0, 1, \dots, m-1\}` such that

.. math::

    \pi[q] = \text{max}\{k : k < q \wedge P_k \sqsupset P_q\}
