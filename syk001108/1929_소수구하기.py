import sys
import math

def primes(M, N):
    is_prime = [True] * (N + 1)
    is_prime[0] = is_prime[1] = False # 0과 1은 소수 아님

    for i in range(2, int(math.sqrt(N)) + 1):
        if is_prime[i]:
            for j in range(i*i, N + 1, i):
                is_prime[j] = False

    for i in range(M, N + 1):
        if is_prime[i]:
            print(i)

M, N = map(int, sys.stdin.readline().split())
primes(M, N)
