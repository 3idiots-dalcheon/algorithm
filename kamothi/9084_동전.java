import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 동전은 오름차순되어 제공된다.
public class boj_9084 {
    static int t,n,m;
    static int[] coin;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());

        for(;t>0;t--){
            n = Integer.parseInt(br.readLine());
            coin = new int[n+1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=1;i<=n;i++) coin[i] = Integer.parseInt(st.nextToken());

            m = Integer.parseInt(br.readLine());

            dp = new int[m+1];
            dp[0] = 1;

            for(int i=1;i<=n;i++){
                for(int j=coin[i];j<=m;j++){
                    dp[j] += dp[j - coin[i]];
                }
            }
            System.out.println(dp[m]);
        }
    }
}
