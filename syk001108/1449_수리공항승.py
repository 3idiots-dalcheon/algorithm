n, l = map(int, input().split())
positions = list(map(int, input().split()))

positions.sort()

count = 0
i = 0

while i < n:
    count += 1
    coverage = positions[i] + l - 1

    while i < n and positions[i] <= coverage:
        i += 1

print(count)
