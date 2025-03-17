n = int(input())

dp = [0] * (n + 1)

# 초기값
dp[1] = 1
if n > 1:
    dp[2] = 1

# 점화식을 이용한 DP 계산
for i in range(3, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]

print(dp[n])
