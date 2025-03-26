import sys

N, K = map(int, sys.stdin.readline().split())  # 물품 수 N, 배낭 최대 무게 K
items = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]  # (무게 W, 가치 V)

# DP 테이블 (1차원 배열 사용)
dp = [0] * (K + 1)

# DP 진행 (물건을 하나씩 확인하며 갱신)
for W, V in items:
    for w in range(K, W - 1, -1): # 무게 제한 K부터 W-1까지 역순으로 탐색
        dp[w] = max(dp[w], dp[w - W] + V)

print(dp[K])
