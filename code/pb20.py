from math import factorial

def pb20(n=100):
    res = sum(map(int, str(factorial(n))))
    print(res)
    return res

pb20()