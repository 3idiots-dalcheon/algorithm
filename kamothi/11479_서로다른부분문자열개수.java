import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

// 서로다른 부분 문자열의 개수
public class boj_11478 {
    static String s;
    static Set<String> hs = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = br.readLine();

        for (int i = 1; i <= s.length(); i++) solve(i);

        System.out.println(hs.size());

    }

    public static void solve(int n){
        for (int i = 0; i <= s.length() - n; i++) {
            String sub = s.substring(i, i + n);
            hs.add(sub);
        }
    }
}
