import sys
import heapq

n = int(sys.stdin.readline())
min_heap = []

for _ in range(n):
  row = list(map(int, sys.stdin.readline().split()))
  for num in row:
    heapq.heappush(min_heap, num)
    if len(min_heap) > n:
      heapq.heappop(min_heap) # heappop하여 루트 노드 꺼냄(힙 안에서 제일 작은거, print하면 루트 노드 프린트 됨)

print(min_heap[0]) 
