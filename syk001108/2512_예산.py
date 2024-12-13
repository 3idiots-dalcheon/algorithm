# 이진 탐색 사용
def allocate_budget(n, requests, total_budget):
    start, end = 0, max(requests)
    result = 0

    while start <= end:
        mid = (start + end) // 2 # 중간값을 상한액으로 설정

        # 예산 합 계산 (상한액 적용)
        allocated_sum = sum(min(mid, req) for req in requests)

        # 예산 합이 총 예산을 넘지 않는 경우
        if allocated_sum <= total_budget:
            result = mid # 현재 상한액을 저장 (최대값 갱신)
            start = mid + 1 # 더 큰 상한액을 시도
        else:
            end = mid - 1 # 예산 초과 시 상한액을 낮춤

    return result

n = int(input()) # 지방 수
requests = list(map(int, input().split())) # 요청 예산
total_budget = int(input()) # 총 예산

print(allocate_budget(n, requests, total_budget))
