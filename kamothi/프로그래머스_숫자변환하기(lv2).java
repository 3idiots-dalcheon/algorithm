import java.util.*;

// x를 y로 변환하기 위한 최소 연산 횟수
class Solution {
    int dp[] = new int[1000001];
    private static final int MAX = Integer.MAX_VALUE;
    public int solution(int x, int y, int n) {
        int answer = 0;
        
        for(int i=x+1;i<=y;i++){
            int a = MAX, b = MAX, c = MAX, d;

            if (isDivided(i, 2) && x < i / 2) a = dp[i / 2];
            if (isDivided(i, 3) && x < i / 3) b = dp[i / 3];
            if (x <= i - n) c = dp[i - n];
            
            d = Math.min(a, b);
            d = Math.min(d, c);
            
            dp[i] = (d < MAX) ? d + 1 : MAX;
        }
        
        answer = (dp[y] < MAX) ? dp[y] : -1;

        return answer;
    }
    private static boolean isDivided(int num, int divide) {
        return (num / divide > 0 && num % divide == 0);
    }
}
