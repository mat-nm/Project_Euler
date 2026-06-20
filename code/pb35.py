from sympy import isprime   

def try_circular(n):
    m = str(n)
    for i in range(len(str(n))+1):
        l = m[0]
        ll = m[1:]
        if (not isprime(int(str(ll)+str(l)))):
            return False
        m = str(ll)+str(l)
    return True

def pb35(n = 10**6):
    res = 1
    for i in range(3, n+1, 2):
        if (isprime(i)) and try_circular(i):
            res += 1
    print(res)
    return res

pb35()