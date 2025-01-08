n, m = map(int, input().split())
sequence = list(range(1, n + 1))
visited = [False] * n
current = []

def dfs():
    if len(current) == m:
        print(' '.join(map(str, current)))
        return

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            current.append(sequence[i])
            dfs()
            current.pop()
            visited[i] = False

dfs()
