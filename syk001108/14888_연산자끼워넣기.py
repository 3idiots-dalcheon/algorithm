import sys

sys.setrecursionlimit(10**6)

def dfs(index, current_result, plus, minus, mul, div):
    global max_result, min_result

    if index == n:
        max_result = max(max_result, current_result)
        min_result = min(min_result, current_result)
        return

    num = numbers[index]

    if plus:
        dfs(index + 1, current_result + num, plus - 1, minus, mul, div)
    if minus:
        dfs(index + 1, current_result - num, plus, minus - 1, mul, div)
    if mul:
        dfs(index + 1, current_result * num, plus, minus, mul - 1, div)
    if div: # C++14 방식 정수 나눗셈
        if current_result < 0:
            dfs(index + 1, -(-current_result // num), plus, minus, mul, div - 1)
        else:
            dfs(index + 1, current_result // num, plus, minus, mul, div - 1)

n = int(input())
numbers = list(map(int, input().split()))
plus, minus, mul, div = map(int, input().split())

# 결과 초기값 설정
max_result = -int(1e9)
min_result = int(1e9)

dfs(1, numbers[0], plus, minus, mul, div)

print(max_result)
print(min_result)
