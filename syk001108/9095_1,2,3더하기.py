def solve():
    import sys
    input = sys.stdin.read
    data = input().split()

    T = int(data[0])
    test = list(map(int, data[1:]))

    max_n = 10
    dp = [0] * (max_n + 1)

    # 초기값 설정
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    # dp 점화식 계산
    for i in range(4, max_n + 1):
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]

    results = [dp[n] for n in test]
    print("\n".join(map(str, results)))

solve()
