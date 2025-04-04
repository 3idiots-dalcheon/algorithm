import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2688 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[][] dp = new long[65][10];

        for (int i = 0; i <= 9; i++) dp[1][i] = 1;

        for (int i = 2; i <= 64; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = j; k <= 9; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            int N = Integer.parseInt(br.readLine());
            long ans = 0;
            for (int i = 0; i <= 9; i++) {
                ans += dp[N][i];
            }
            System.out.println(ans);
        }



    }
}
