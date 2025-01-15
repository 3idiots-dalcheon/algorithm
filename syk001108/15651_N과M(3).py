n, m = map(int, input().split())
sequence = []
def dfs(sequence):
    if len(sequence) == m:
        print(' '.join(map(str, sequence)))
        return

    for i in range(1, n + 1):
        dfs(sequence + [i])

dfs([])
