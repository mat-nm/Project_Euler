def pb56(B=100):
    s = 0
    for y in range(B):
        for x in range(B):
            c = sum(map(int, str(x**y)))
            if c > s:
                s = c 
    print(s)
    return s

pb56()