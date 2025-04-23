function solution(s) {
    const nums = s.split(' ').map(Number); // 공백 기준으로 나누고 숫자로 변환
    const min = Math.min(...nums); // (...) spread 문법으로 배열을 개별 요소로 풀어서 전달
    const max = Math.max(...nums);
    var answer = `${min} ${max}`; // 템플릿 리터럴( ${} )사용하므로 백틱(``)으로 감싸야 함
    return answer
}
