n, m = map(int, input().split())
numbers = sorted(map(int, input().split()))

def dfs(start, sequence):
    if len(sequence) == m:
        print(" ".join(map(str, sequence)))
        return
    
    for i in range(start, n):
        dfs(i + 1, sequence + [numbers[i]])

dfs(0, [])
