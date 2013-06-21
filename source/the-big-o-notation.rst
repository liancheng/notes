############
`O`-notation
############

Think of `f(n)` and `g(n)` as the running times of two algorithms on inputs of size `n`.

    Let `f(n)` and `g(n)` be functions from positive integers to positive reals.  We say `f=O(g)` (which means that "`f` grows no faster than `g`") if there is a constant `c > 0` such that `f(n) \leq c \cdot g(n)`. Or

        `f=O(g) \iff (\exists x_0, c \in \mathcal{R})(\forall x \in \mathcal{R})[x > x_0 \implies f(n) \leq c \cdot g(n)]`

    At the same time, we have:

        `f=\Omega(g) \iff g=O(f)`

        `f=\Theta(g) \iff f=O(g) \wedge f=\Omega(g)`

Examples
========

 Exponential dominates polynomial:

     `(\forall a, b \in \mathcal{R})[a>1 \implies a^n=\Omega(n^b)]`

 `(\forall a, b \in \mathcal{R})[a>b \implies a^n=\Omega(b^n)]`

 Polynomial dominates polylogarithmic:

     `(\forall a, b \in \mathcal{N}^+)[n^a=\Omega(\log^b(n))]`
