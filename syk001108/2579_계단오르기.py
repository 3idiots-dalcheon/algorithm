import sys

def max_stair_score(n, stair):
    if n == 1:
        return stair[1]

    dp = [0] * (n + 1)
    dp[1] = stair[1]
    
    if n >= 2:
        dp[2] = stair[1] + stair[2]
    
    if n >= 3:
        dp[3] = max(stair[1] + stair[3], stair[2] + stair[3])
    
    for i in range(4, n + 1):
        dp[i] = max(dp[i-3] + stair[i-1] + stair[i], dp[i-2] + stair[i])

    return dp[n]

n = int(sys.stdin.readline().strip())
stair = [0] + [int(sys.stdin.readline().strip()) for _ in range(n)]

print(max_stair_score(n, stair))
