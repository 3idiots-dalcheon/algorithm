str = input().split('-') # '-' 기준으로 문자열 나누기

# 첫 번째 그룹은 더하고 이후 그룹은 더한 후 빼기
result = sum(map(int, str[0].split('+')))

for part in str[1:]:
    result -= sum(map(int, part.split('+')))

print(result)
