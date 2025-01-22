S = input().strip()
unique_substrings = set() # set은 중복 자동으로 제거

for i in range(len(S)):
    for j in range(i + 1, len(S) + 1): # [i:j]면 [i:j-1] 반환하므로 +1 해줌
        unique_substrings.add(S[i:j])

print(len(unique_substrings))
