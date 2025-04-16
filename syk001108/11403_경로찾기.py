n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

def dfs(start, visited):
    for i in range(n):
        if graph[start][i] == 1 and not visited[i]:
            visited[i] = True
            dfs(i, visited)

result = [[0] * n for _ in range(n)]

for i in range(n):
    visited = [False] * n
    dfs(i, visited)
    for j in range(n):
        if visited[j]:
            result[i][j] = 1

for row in result:
    print(*row)
  
