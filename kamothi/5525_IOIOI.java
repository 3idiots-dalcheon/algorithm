import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class boj_5525 {
    static int N,M;
    static String S;
    static int[] d = new int[10000000];
    static int result;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        S = br.readLine();



        for (int i=1;i<M-1;i++) {
            if (S.charAt(i) == 'O' && S.charAt(i+1) == 'I') {
                d[i+1] = d[i-1] + 1;

                if (d[i+1] >= N && S.charAt(i-2*N+1) == 'I') result++;

            }
        }
        System.out.println(result);


    }
}
