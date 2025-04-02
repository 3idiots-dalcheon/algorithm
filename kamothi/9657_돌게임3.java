import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9657 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        int[] dp = new int[1001];

        dp[1] = 1; dp[2] = 0;dp[3] = 1; dp[4] = 1; dp[5]=1;

        for(int i=6;i<=n;i++){
            if(dp[i-1] == 0 || dp[i-3] == 0 || dp[i-4] == 0) dp[i] = 1;
            else dp[i] = 0;
        }


        if(dp[n] == 1) System.out.println("SK");
        else System.out.println("CY");
    }
}
