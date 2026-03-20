import sys
from collections import deque
input=sys.stdin.readline

n, m  = map(int, input().split())
arr = [list(map(int,input().rstrip().split())) for _ in range(n+m)]
cnt = [10**9] * (101)
move = {}

for x, y in arr:
    move[x] = y

def bfs():
    queue = deque([(1,0)])

    while queue:
        nowX, nowCnt = queue.popleft()

        if nowCnt >= cnt[nowX]: 
            continue

        cnt[nowX] = nowCnt

        if nowX == 100:
            print(nowCnt)
            return

        for i in range(1,7):
            nx = nowX + i

            if nx > 100:
                continue
            
            if nx in move:
                nx = move[nx]

            if nowCnt + 1 < cnt[nx]:
                queue.append((nx, nowCnt + 1))

bfs()
