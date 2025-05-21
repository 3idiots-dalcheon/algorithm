import java.util.*;

class Solution {
    public String solution(String s) {
        StringBuilder result = new StringBuilder();
        
        int flag = 0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c == ' ') flag = -1;

            if(Character.isDigit(c)) {
                result.append(c);
                flag++;
                continue;
            }

            if(flag == 0) 
                result.append(Character.toUpperCase(c));
            else
                result.append(Character.toLowerCase(c));

            flag++;
        }

        return result.toString();
    }
}
