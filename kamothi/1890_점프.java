import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1890 {
    static int n;
    static long[][] map = new long[101][101];
    static long[][] dp = new long[101][101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for(int i=1;i<=n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1;j<=n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[1][1] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j] == 0) continue;

                if(map[i][j] + j <= n) dp[i][(int) (j+map[i][j])] += dp[i][j];
                if(i+map[i][j] <= n) dp[(int) (i+map[i][j])][j] += dp[i][j];
            }
        }

        System.out.println(dp[n][n]);
    }
}
