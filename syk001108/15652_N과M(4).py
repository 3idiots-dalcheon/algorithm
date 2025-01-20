n, m = map(int, input().split())
sequence = []
def dfs(sequence):
    if len(sequence) == m:
        print(' '.join(map(str, sequence)))
        return
    start = sequence[-1] if sequence else 1 # sequence 리스트의 마지막 원소를 가져오는데 sequence 비워져있으면 1로 시작
    
    for i in range(start, n + 1):
        dfs(sequence + [i])

dfs([])
