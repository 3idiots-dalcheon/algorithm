import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = n;
        String str = Integer.toBinaryString(n);
        String tmp = str.replace("0","");
        int count = tmp.length();
        
        while(true){
            answer++;
            str = Integer.toBinaryString(answer);
            tmp = str.replace("0","");
            int count1 = tmp.length();
            if(count == count1) return answer;
        }
    }
}
