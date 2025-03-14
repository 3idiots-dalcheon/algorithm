import sys

n, m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

prefix = [0] * (n + 1)
for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + arr[i - 1]

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(prefix[j] - prefix[i - 1])
