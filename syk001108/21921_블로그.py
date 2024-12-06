n, x = map(int, input().split()) # 입력 받아 공백 단위로 split -> map으로 int 변환 -> n, x에 각각 저장
visitors = list(map(int, input().split())) # 리스트로 저장

current_sum = sum(visitors[:x])  # 첫 x일 방문자 수의 합
max_sum = current_sum
max_count = 1

# 슬라이딩 윈도우 사용
for i in range(x, n):
    current_sum += visitors[i] - visitors[i - x]  # 윈도우 이동 (새로운 날 추가, 이전 날 제거)
    if current_sum > max_sum:
        max_sum = current_sum
        max_count = 1
    elif current_sum == max_sum:
        max_count += 1

if max_sum == 0:
    print("SAD")
else:
    print(max_sum)
    print(max_count)
