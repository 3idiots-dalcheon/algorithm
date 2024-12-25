import heapq
import sys

def christmas_gift():
    data = sys.stdin.read().splitlines()
    n = int(data[0])
    max_heap = []
    results = []

    for line in data[1:]:
        values = list(map(int, line.split()))
        a = values[0]

        if a == 0: # 아이 만난 경우
            if max_heap:
                results.append(-heapq.heappop(max_heap)) # 가장 큰 값 꺼내 저장
            else:
                results.append(-1) # 줄 선물 없는 경우
        else: # 거점지에서 선물 충전
            for gift in values[1:]:
                heapq.heappush(max_heap, -gift) # 최대 힙 위해 음수로 저장

    for result in results:
        print(result)

christmas_gift()
