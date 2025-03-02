import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_13305 {
    static int n;
    static long[] dist = new long[100000];
    static long[] L = new long[100001];
    static long result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n-1;i++) {
            dist[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            L[i] = Integer.parseInt(st.nextToken());
        }

        long MIN = Integer.MAX_VALUE;
        for(int i=1;i<n;i++){
            MIN = Math.min(MIN, L[i-1]);
            result += dist[i-1]*MIN;
        }

        System.out.println(result);
    }
}
