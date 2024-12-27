def getAnswer(n, m, picked, last):
    if len(picked) >= m:
        print(*picked)
        return
    
    for i in range(last+1, n+1):
        picked.append(i)
        getAnswer(n, m, picked, i)
        picked.pop()

n, m  = map(int, input().split())

getAnswer(n, m, [], 0)