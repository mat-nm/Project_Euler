def solve():
    sum = 0
    for i in range(2, 295246):
        s = 0
        for j in range(len(str(i))):
            s += int(str(i)[j])**5
        if s == i:
            sum += i
            #print(i)
    print(sum)
    return (sum)

solve()