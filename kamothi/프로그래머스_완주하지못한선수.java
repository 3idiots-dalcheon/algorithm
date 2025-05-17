import java.util.*;

// 완주하지 못한 선수의 이름을 return
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> m = new HashMap<>();
        
        for(String a : participant){
            m.put(a, m.getOrDefault(a, 0) + 1);
        }
        
        for(String a : completion){
            m.put(a, m.get(a) -1);
        }
        
        for (String key : m.keySet()) {
            if (m.get(key) != 0) {
                answer = key;
            }
        }
        
        return answer;
    }
}
