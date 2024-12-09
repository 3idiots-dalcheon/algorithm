#20920 영단어 암기는 괴로워
n, m = map(int, input().split())

word_count = {}
for _ in range(n):
    word = input().strip()
    if len(word) >= m:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1

# 정렬 기준 (빈도수(내림차순), 단어 길이(내림차순), 단어(오름차순))
sorted_words = sorted(word_count.keys(), key=lambda word: (-word_count[word], -len(word), word))

for word in sorted_words:
    print(word)
