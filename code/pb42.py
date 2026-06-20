from urllib import request
from math import isqrt, sqrt

def pb42():
    url = "https://projecteuler.net/resources/documents/0042_words.txt"
    f = request.urlopen(url)
    line = f.read().decode('utf-8')
    f.close()
    L = list(line[1:-1].split('","'))
    res = 0
    for name in L:
        t = sum(map(lambda c : ord(c) - ord('A') + 1, name))
        if (sqrt(1 + 8*t)) == isqrt(1 + 8*t):
            res += 1
    print(res)
    return res

pb42()