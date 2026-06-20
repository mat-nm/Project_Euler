def is_palindromic(num):
    s = str(num)
    n = len(s)
    for i in range(n):
        if s[i] != s[n-i-1]:
            return False
    return True

def solve():
    sum = 0
    for i in range (1, 10**6+1):
        if is_palindromic(i) and is_palindromic(bin(i)[2:]):
            sum += i
    print(sum)
    return sum

solve()