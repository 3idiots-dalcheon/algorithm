#BFS-최단경로
from collections import deque

moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

def bfs(l, start, end):
    visited = [[False] * l for _ in range(l)] # 모든 칸 방문 안 함으로 초기화
    queue = deque([(start[0], start[1], 0)]) # 큐 초기화(마지막은 이동 횟수)
    visited[start[0]][start[1]] = True # 시작 위치 방문 표시
    
    while queue:
        x, y, count = queue.popleft() # 가장 먼저 들어간 현재 위치 정보 꺼내고 pop
        
        if (x, y) == end: # 현재 위치와 도착지 같으면 종료
            return count
        
        for dx, dy in moves:
            nx, ny = x + dx, y + dy # 새로운 위치 계산(moves에서 꺼내옴)
            
            if 0 <= nx < l and 0 <= ny <l and not visited[nx][ny]: # 체스판 벗어나는지 체크 & 방문 안 했는지 체크
                visited[nx][ny] = True # 방문 표시
                queue.append((nx, ny, count + 1)) # 이동 횟수 증가해서 큐 삽입

t = int(input())

for _ in range(t):
    l = int(input())
    start = tuple(map(int, input().split()))
    end = tuple(map(int, input().split()))
    
    print(bfs(l, start, end))
