function solution(n) {
    const countOne = (num) => num.toString(2).split('').filter(c => c === '1').length; // filter(c => c === '1') => 배열에서 1만 남

    const targetCount = countOne(n);
    var answer = n + 1;

    while (countOne(answer) !== targetCount) {
        answer++;
    }

    return answer;
}
