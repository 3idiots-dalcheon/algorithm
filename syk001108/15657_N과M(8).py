n, m = map(int, input().split())
numbers = sorted(list(map(int, input().split())))
sequence = []

def dfs(sequence):
    if len(sequence) == m:
        print(' '.join(map(str, sequence)))
        return

    for i in numbers:
        if not sequence or sequence[-1] <= i:
            dfs(sequence + [i])
            
dfs([])
