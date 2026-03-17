import sys
import math

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    answer = math.comb(M, N)
    print(answer)
