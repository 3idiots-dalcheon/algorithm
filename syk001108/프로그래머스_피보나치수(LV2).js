function solution(n) {
    var answer = 0;
    
    const fib = new Array(n + 1).fill(0);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (let i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
    }

    answer = fib[n];
    
    return answer;
}
