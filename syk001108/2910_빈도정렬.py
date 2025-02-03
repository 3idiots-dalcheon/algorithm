from collections import Counter

n, c = map(int, input().split())
numbers = list(map(int, input().split()))

freq = Counter(numbers)

order = {}
for i, num in enumerate(numbers):
    if num not in order:
        order[num] = i

sorted_numbers = sorted(numbers, key=lambda x: (-freq[x], order[x]))

print(*sorted_numbers)
