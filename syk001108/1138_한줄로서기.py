N = int(input())
info = list(map(int, input().split()))
line = [0] * N

for i in range(N):
    count = info[i]
    for j in range(N):
        if line[j] == 0:
            if count == 0:
                line[j] = i + 1
                break
            count -= 1

print(' '.join(map(str, line)))
