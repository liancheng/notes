from numpy import matrix

f = matrix((0, 1))
f.resize(2, 1)

a = matrix(((0, 1), (1, 1)))

def fibonacci(n):
    return (a ** n * f)[0, 0]

