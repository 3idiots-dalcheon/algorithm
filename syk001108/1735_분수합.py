import math

A, B = map(int, input().split())

C, D = map(int, input().split())

numerator = A * D + C * B # 분자
denominator = B * D # 분모

# 최대공약수
gcd = math.gcd(numerator, denominator)

# 기약분수 변환
numerator //= gcd
denominator //= gcd

print(numerator, denominator)
