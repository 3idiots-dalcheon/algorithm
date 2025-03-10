import sys

def padovan_sequence():
    dp = [0] * 101 # N 최대값이 100이므로 충분히 배열 할당(100으로 하니 런타임 에러)
    dp[1] = dp[2] = dp[3] = 1
    dp[4] = dp[5] = 2
    
    # 점화식 이용해 DP 배열 채우기
    for i in range(6, 101):
        dp[i] = dp[i-1] + dp[i-5]
    
    return dp

# 미리 계산된 파도반 수열 배열 가져오기
dp = padovan_sequence()

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    print(dp[N])
