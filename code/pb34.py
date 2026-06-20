from math import factorial

def solve():
    sum = 0
    for i in range(3, 1000000):
        s = 0
        for j in range(len(str(i))):
            s += factorial(int(str(i)[j]))
        if s == i:
            sum += i
            # print(i)
    print(sum)
    return (sum)

solve()