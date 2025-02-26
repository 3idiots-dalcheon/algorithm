import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_14501 {
    static int n;
    static int[][] arr = new int[30][2];
    static int[] dp = new int[30];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for(int i=n;i>0;i--){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i=1;i<=n;i++){
            if (arr[i][0] > i) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = Math.max(dp[i - 1], arr[i][1] + dp[i - arr[i][0]]);
            }
        }

        System.out.println(dp[n]);


    }
}
