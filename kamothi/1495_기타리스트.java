import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 마지막 곡을 연주할 수 있는 볼륨 중 최대값
// 앞에 값에서 +한거, 앞에 값에서 -한거
public class boj_1495 {
    static int n, s, m;
    static boolean[][] dp;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[n+1];
        for(int i=1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dp = new boolean[n+1][m+1];
        if(arr[1] + s <= m) dp[1][arr[1]+s] = true;
        if(s - arr[1] >= 0) dp[1][s-arr[1]] = true;

        for(int i=2;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(dp[i - 1][j]){
                    if(arr[i] + j <= m) dp[i][arr[i] + j] = true;
                    if(j - arr[i] >= 0) dp[i][j - arr[i]] = true;
                }
            }
        }

        for(int i=m;i>=0;i--){
            if(dp[n][i]) {
                System.out.println(i);
                return;
            }
        }

        System.out.println(-1);
    }
}
