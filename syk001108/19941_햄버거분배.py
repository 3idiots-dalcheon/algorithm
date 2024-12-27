def max_hamburgers(N, K, table):
    eat = [False] * N
    max_people = 0 # 햄버거 먹을 수 있는 사람 수

    for i in range(N):
        if table[i] == 'P':
            for j in range(max(0, i - K), min(N, i + K + 1)): # K 범위 내 햄버거 탐색
                if table[j] == 'H' and not eat[j]: # 먹을 수 있는 햄버거 있으면
                    eat[j] = True # 햄버거 먹음으로 표시
                    max_people += 1
                    break # 햄버거 먹었으니 종료
    return max_people

N, K = map(int, input().split())
table = input().strip()

print(max_hamburgers(N, K, table))
