import sys
import heapq

input = sys.stdin.readline
N = int(input())

heap = []

for _ in range(N):
    x = int(input())
    
    if x != 0:
        # 절댓값 기준으로 정렬함-> 값이 같으면 실제 값 기준
        heapq.heappush(heap, (abs(x), x))
    else:
        if heap:
            # 실제 값만 출력
            print(heapq.heappop(heap)[1])
        else:
            print(0)
