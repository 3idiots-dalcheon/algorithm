# 투 포인터 이용하여 좌, 우 방향의 인덱스를 이용하여 한 번의 배열 탐색으로 두 수의 합이 x가 되는 쌍을 찾을 수 있음

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline())

# 정렬 (투 포인터 사용 위해)
arr.sort()

# 투 포인터 설정
left, right = 0, n - 1
count = 0 # 정답 개수

while left < right:
    current_sum = arr[left] + arr[right]

    if current_sum == x:
        count += 1
        left += 1 # 다음 쌍 찾기 위해 이동
        right -= 1
    elif current_sum < x:
        left += 1 # 합 부족-> 작은 값 증가
    else:
        right -= 1 # 합 초과-> 큰 값 감소

print(count)
