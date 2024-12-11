from collections import Counter

def palindrome(name):
    counter = Counter(name) # 카운터로 각 알파벳 개수 세기
    odd_char = '' # 홀수 개수를 가지는 알파벳 저장될 변수
    half_palindrome = [] # 팰린드롬의 절반을 저장할 리스트

    for char, count in sorted(counter.items()):
        if count % 2 == 1: # 홀수 개수 알파벳
            if odd_char: # 이미 홀수 알파벳이 하나 존재하면 팰린드롬 안 됨
                return "I'm Sorry Hansoo"
            odd_char = char # 홀수 알파벳을 저장
        half_palindrome.extend(char * (count // 2))  # 절반하여 팰린드롬 첫 번째 절반에 추가

    first_half = ''.join(half_palindrome) # 팰린드롬의 첫 번째 절반
    second_half = first_half[::-1] # 팰린드롬의 두 번째 절반 (반대순서로)
    return first_half + odd_char + second_half # 팰린드롬 완성

if __name__ == "__main__":
    name = input().strip() # 이름 입력 (영어)
    print(palindrome(name))
