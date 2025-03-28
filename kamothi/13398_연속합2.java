import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_13398 {
    static int n;
    static int[] arr;
    static int[] left;
    static int[] right;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        left = new int[n];
        right = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if(n==1) {
            System.out.println(arr[0]);
            return;
        }

        left[0] = arr[0];
        right[n-1] = arr[n-1];
        answer = arr[0];
        for(int i=1;i<n;i++) {
            left[i] = Math.max(arr[i],left[i-1]+arr[i]);
            answer = Math.max(answer,left[i]);
        }
        for(int i=n-2;i>=0;i--) right[i] = Math.max(arr[i],right[i+1]+arr[i]);

        for(int i=1;i<n-1;i++){
            answer = Math.max(answer, Math.max(arr[i] + left[i-1] + right[i+1], left[i - 1] + right[i + 1]));
        }

        System.out.println(answer);
    }
}
