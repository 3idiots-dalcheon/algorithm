import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17609 {
    static int t;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());

        while(t-->0){
            String now = br.readLine();
            int right = now.length()-1, left = 0;
            int answer  = palindrome(now, left, right, 0);

            System.out.println(answer);
        }
    }

    public static int palindrome(String now, int left, int right, int answer){
        while(left < right){
            if(now.charAt(left) == now.charAt(right)){
                left++; right--;
                continue;
            }
            if (answer != 0)
                return 2;
            answer++;
            int res = palindrome(now, left, right-1, answer);
            if (res == 1) {
                right--;
                continue;
            }
            res = palindrome(now, left+1, right, answer);
            if (res == 1) {
                left++;
                continue;
            }
        }
        return answer;
    }
}
