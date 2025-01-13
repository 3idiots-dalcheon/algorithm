from collections import Counter

t = int(input()) # 테스트 케이스 수

for _ in range(t):
    n = int(input()) # 의상 수
    clothes = []

    for _ in range(n):
        _, kind = input().split()
        clothes.append(kind)

    # 종류별 의상 개수 세기
    counter = Counter(clothes)

    combinations = 1
    for count in counter.values():
        combinations *= (count + 1)

    print(combinations - 1)
