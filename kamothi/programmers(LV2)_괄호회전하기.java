import java.util.Stack;

class Solution {
    public boolean check(String s){
        boolean flag = true;
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '[' || s.charAt(i) == '{' || s.charAt(i) == '('){
                st.push(s.charAt(i));
                continue;
            }
            else{
                if(st.isEmpty()) {
                    flag = false;
                    break;
                }
                char t = st.peek();
                if(s.charAt(i) == '}' && t == '{') st.pop();
                else if(s.charAt(i) == ']' && t == '[') st.pop();
                else if(s.charAt(i) == ')' && t == '(') st.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }
        
        if(!st.isEmpty()) flag = false;
        return flag;
    }
    
    public int solution(String s) {
        int answer = 0;
        for(int i=0;i<s.length();i++){
            s = s.substring(1) + s.charAt(0);
            if(check(s)) answer++;
        }
        
        return answer;
    }
}
