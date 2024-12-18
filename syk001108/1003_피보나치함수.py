def fibonacci_count():
    # 0과 1이 출력되는 횟수를 저장할 DP 테이블
    dp_0 = [0] * 41
    dp_1 = [0] * 41
    
    # 초기값 설정
    dp_0[0], dp_1[0] = 1, 0 # fibonacci(0)
    dp_0[1], dp_1[1] = 0, 1 # fibonacci(1)
    
    # DP로 2부터 40까지의 결과 계산
    for i in range(2, 41):
        dp_0[i] = dp_0[i-1] + dp_0[i-2]
        dp_1[i] = dp_1[i-1] + dp_1[i-2]
    
    return dp_0, dp_1

def main():
    dp_0, dp_1 = fibonacci_count()
    
    T = int(input()) # 테스트 케이스 개수
    for _ in range(T):
        N = int(input()) # N값 입력
        print(dp_0[N], dp_1[N]) # 0과 1 출력 횟수 출력

if __name__ == "__main__":
    main()
