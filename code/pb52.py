def tab(i):
    L = [0] * 10
    # print("len L")
    # print(len(L))
    for j in (str(i)):
        # print(int(j))
        L[(int(j))] += 1
    return L

def pb52():
    i = 2
    while True:
        L = tab(i)
        if L == tab(2*i) and L == tab(3*i) and L == tab(3*i) and L == tab(4*i) and L == tab(5*i) and L == tab(6*i):
            print(i)
            return
        i += 1
pb52()