import sys

N = int(sys.stdin.readline())
cost = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# DP 테이블 초기화
dp = [[0] * 3 for _ in range(N)]
dp[0] = cost[0]  # 첫째 집은 초기 비용 그대로

# DP 점화식 적용
for i in range(1, N):
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0] # 빨강
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1] # 초록
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2] # 파랑

print(min(dp[N-1]))
