def solve():
    with open("./pb22_names.txt", "r") as f:
        l = f.read()

    names = sorted(l[1:-1].split('","'))

    res = 0
    for i, name in enumerate(names, start=1):
        score = 0
        for c in name:
            score += ord(c) - ord('A') + 1
        res += score * i

    print(res)
    return res

solve()