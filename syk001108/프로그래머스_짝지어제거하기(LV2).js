function solution(s) {
    const stack = [];

    for (let i = 0; i < s.length; i++) {
        const current = s[i];
        if (stack.length > 0 && stack[stack.length - 1] === current) {
            stack.pop(); // 짝이면 제거
        } else {
            stack.push(current); // 아니면 추가
        }
    }

    return stack.length === 0 ? 1 : 0;
}
