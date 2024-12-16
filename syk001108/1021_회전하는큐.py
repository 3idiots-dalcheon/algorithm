from collections import deque

def min_operations(N, M, targets):
    # 1부터 N까지의 숫자를 가진 덱 초기화
    dq = deque(range(1, N+1))
    operations = 0  # 연산 횟수 누적
    
    for target in targets:
        # target 위치 찾음
        target_idx = dq.index(target)
        
        # 왼쪽으로 이동하는 횟수와 오른쪽으로 이동하는 횟수 중 최솟값 선택
        left_moves = target_idx
        right_moves = len(dq) - target_idx
        operations += min(left_moves, right_moves)
        
        # 덱을 이동
        if left_moves <= right_moves:
            dq.rotate(-left_moves)
        else:
            dq.rotate(right_moves)
        
        # 첫 번째 원소(목표) 제거
        dq.popleft()
    
    return operations

N, M = map(int, input().split())
targets = list(map(int, input().split()))

print(min_operations(N, M, targets))
