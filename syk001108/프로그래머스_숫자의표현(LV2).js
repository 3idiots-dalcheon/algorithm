function solution(n) {
    let answer = 0;
    
    for (let k = 1; k * (k - 1) / 2 < n; k++) {
        const numerator = n - (k * (k - 1)) / 2;
        if (numerator % k === 0) {
            answer++;
        }
    }

    return answer;
}
