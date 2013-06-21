from itertools import permutations
[v for v in permutations(range(8) if 8 == len({v[i] + i for i in range(8)})
                                       == len({v[i] - i for i in range(8)})]
