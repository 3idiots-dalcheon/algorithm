import sys
import heapq

input = sys.stdin.readline
N = int(input())
max_heap = []

for _ in range(N):
    x = int(input())
    if x > 0:
        heapq.heappush(max_heap, -x) # 최대 힙을 위해 음수로 저장
    else:
        if max_heap:
            print(-heapq.heappop(max_heap)) # 다시 양수로 바꿔 출력
        else:
            print(0)
