function solution(s) {
    var answer = [];
    let count = 0; // 변환 횟수
    let removedZero = 0; // 제거한 0의 총 개수

    while (s !== "1") {
        let zeroCount = (s.match(/0/g) || []).length; // 현재 문자열에서 0의 개수
        removedZero += zeroCount; // 제거한 0 누적
        s = s.replace(/0/g, ''); // 0 제거
        s = s.length.toString(2); // 길이를 2진수로 변환
        count++; // 변환 횟수 증가
    }
    answer = [count, removedZero];
    return answer
}
