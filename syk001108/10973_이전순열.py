def prev(arr):
    n = len(arr)

    # 뒤 부터 내림차순 깨지는 곳 찾기
    i = n - 1
    while i > 0 and arr[i - 1] <= arr[i]:
        i -= 1
    
    # 오름차순 순이면 -1
    if i == 0:
        return -1

    # i-1위치보다 작은 값 중 가장 큰 값 찾기
    j = n - 1
    while arr[j] >= arr[i - 1]:
        j -= 1

    arr[i - 1], arr[j] = arr[j], arr[i - 1] # 교환

    # i 이후의 값들 내림차순 정렬
    arr[i:] = reversed(arr[i:])

    return arr

N = int(input())
arr = list(map(int, input().split()))

result = prev(arr)

if result == -1:
    print(-1)
else:
    print(*result)
