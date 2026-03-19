import sys
input=sys.stdin.readline

n, m = map(int, input().split())

pairs = {}

for _ in range(n):
    (key,value) = input().split()
    pairs[key] = value
    
for _ in range(m):
    key = input().strip()
    print(pairs[key])
