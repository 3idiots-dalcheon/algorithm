function solution(arr) {
    const gcd = (a, b) => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return a;
    };

    const lcm = (a, b) => (a * b) / gcd(a, b);

    return arr.reduce((acc, cur) => lcm(acc, cur)); // reduce => 배열의 모든 값을 누적 계산할 때 사용
}
