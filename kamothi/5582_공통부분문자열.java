import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// LCS
public class boj_5582 {
    static String s1,s2;
    static int[][] dp = new int[4001][4001];
    static int result;
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        s1 = br.readLine();
        s2 = br.readLine();

        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1.charAt(i-1) == s2.charAt(j-1)) dp[i][j] = dp[i-1][j-1] + 1;
                result = Math.max(result, dp[i][j]);
            }
        }

        System.out.println(result);
    }
}
