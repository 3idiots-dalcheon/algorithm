n = int(input())
schedule = [tuple(map(int, input().split())) for _ in range(n)]

# DP 테이블 생성
dp = [0] * (n + 2)

# DP 역순 계산
for i in range(n, 0, -1):
    t, p = schedule[i - 1]
    if i + t <= n + 1: # 상담 끝나는 날이 퇴사일을 넘지 않는 경우
        dp[i] = max(dp[i + 1], p + dp[i + t])
    else: # 상담 불가능한 경우
        dp[i] = dp[i + 1]

print(dp[1])
