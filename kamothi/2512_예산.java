import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_2512 {
    static int n;
    static int sum;
    static int[] arr;
    static int result;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        sum = Integer.parseInt(br.readLine());

        solve();

        System.out.println(result);
    }

    public static void solve(){
        int left = 0, right = arr[n-1];

        while (left <= right) {
            int mid = (left + right) / 2;
            int tmp = 0;

            for(int i=0;i<n;i++){
                tmp += Math.min(arr[i], mid);
            }

            if (tmp <= sum) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
    }
}
