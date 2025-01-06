from collections import deque

import sys
input = sys.stdin.read
data = input().strip().split('\n')

t = int(data[0])

for i in range(t):
    n, m = map(int, data[2 * i + 1].split())
    priorities = list(map(int, data[2 * i + 2].split()))

    queue = deque(priorities)
    sorted_priorities = sorted(priorities, reverse=True)
    
    order = 0

    while queue:
        if queue[0] == sorted_priorities[0]:
            queue.popleft()
            sorted_priorities.pop(0)
            order += 1

            if m == 0:
                print(order)
                break
        else:
            queue.append(queue.popleft())
        
        m = (m - 1) % len(queue)
