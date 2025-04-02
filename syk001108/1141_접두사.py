import sys

N = int(sys.stdin.readline().strip())
words = [sys.stdin.readline().strip() for _ in range(N)]

words.sort()

ans = N # 처음엔 접두사X 집합인 부분집합의 최대 크기를 전체 개수로 저장

for i in range(N):
    for j in range(i + 1, N):
        if words[j].startswith(words[i]): # words[i]가 words[j]의 접두어인지 확인
            ans -= 1
            break # 이미 하나라도 접두어면 더 이상 확인할 필요X

print(ans)
