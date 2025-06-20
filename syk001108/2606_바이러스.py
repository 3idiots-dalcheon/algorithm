n = int(input()) # 컴퓨터 수
m = int(input()) # 연결된 쌍 수

graph = [[] for _ in range(n + 1)] # 그래프 초기화
visited = [False] * (n + 1)

def dfs(v):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

# 간선 정보 저장 (무방향)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(1) # 1번부터 DFS 실행

print(visited.count(True) - 1) # 1번 제외 결과 출력
