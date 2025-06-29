from collections import deque

N, M = map(int, input().split())
maze = [list(map(int, list(input().strip()))) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            if maze[nx][ny] == 0: # 벽이거나 이미 방문한 경우
                continue

            if maze[nx][ny] == 1:
                maze[nx][ny] = maze[x][y] + 1 # 이전 칸까지 거리 + 1
                queue.append((nx, ny))

    return maze[N - 1][M - 1] # 최종 위치 값 = 최소 거리

print(bfs(0, 0))
