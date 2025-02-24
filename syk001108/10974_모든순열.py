n = int(input())

numbers = list(range(1, n + 1))
visited = [False] * (n + 1)
sequence = []

def dfs():
    if len(sequence) == n:
        print(' '.join(map(str, sequence)))
        return
    
    for i in numbers:
        if not visited[i]:
            visited[i] = True
            sequence.append(i)
            dfs()
            sequence.pop()
            visited[i] = False

dfs()
