# dp[i][0] = i번째 줄에 사자 없음
# dp[i][1] = i번째 줄에 왼쪽 칸에 사자
# dp[i][2] = i번째 줄에 오른쪽 칸에 사자

n = int(input())

dp = [[0] * 3 for _ in range(n + 1)]

# 초기값
dp[1][0] = 1
dp[1][1] = 1
dp[1][2] = 1

mod = 9901

for i in range(2, n + 1):
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod # 사자 안 넣으면 이전 줄 어느 배치든 가능
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod

result = (dp[n][0] + dp[n][1] + dp[n][2]) % mod
print(result)
