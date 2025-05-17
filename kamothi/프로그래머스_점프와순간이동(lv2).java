import java.util.*;

// k칸을 점프하면 k만큼의 건전지 사용량이 든다.
// 순간이동(현재까지 온 거리*2 위치로 이동)은 줄어들지 않음 <- 이게 효율적
// 점프는 최소화하며 N만큼 떨어진 곳으로 이동
// 2배인걸 생각해야함.
public class Solution {
    public int solution(int n) {
        int ans = 1;
        
        while(n>1){
            if(n%2 != 0){
                ans++;
                n-=1;
            }
            else {
                n /= 2;
            }
        }
        

        return ans;
    }
}
