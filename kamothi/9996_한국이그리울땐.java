import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_9996 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String target = br.readLine();

        String[] str = target.split("\\*");
        for(int i=0; i<n; i++) {
            String word = br.readLine();
            if (str[0].length() + str[1].length() > word.length()) {
                System.out.println("NE");
                continue;
            }

            String start = word.substring(0, str[0].length());
            String end = word.substring(word.length()-str[1].length(), word.length());

            if(start.equals(str[0]) && end.equals(str[1])) System.out.println("DA");
            else System.out.println("NE");
        }
    }
}
