def fibo():
    a = 1
    b = 1
    i = 2
    while (b < 10**999):
        a, b = b, a+b
        i += 1
    print(i)
    return i

fibo()