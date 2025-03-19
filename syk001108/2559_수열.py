import sys

n, k = map(int, sys.stdin.readline().split())
temps = list(map(int, sys.stdin.readline().split()))

# 초기 K일 합
now_sum = sum(temps[:k])
max_sum = now_sum

# 슬라이딩 윈도우 적용
for i in range(k, n):
    now_sum += temps[i] - temps[i - k] # 새로운 값 추가 & 앞 값 제거
    max_sum = max(max_sum, now_sum)

print(max_sum)
