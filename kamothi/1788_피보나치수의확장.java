import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1788 {
    public static void main(String[] args) throws IOException {
        int[] dp = new int[1000001];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if(n > 0){
            System.out.println(1);
        }
        else if(n < 0){
            n = -n;
            if(n%2 ==0) {
                System.out.println(-1);
            }else {
                System.out.println(1);
            }
        }
        else System.out.println(0);

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2;i<=1000000;i++){
            dp[i] = (dp[i-2]%1000000000 + dp[i-1]%1000000000)%1000000000;
        }

        System.out.println(dp[n]);
    }
}
