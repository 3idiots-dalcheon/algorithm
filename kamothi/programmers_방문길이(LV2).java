import java.util.*;

// 상하좌우 이동
// 좌표평면의 경계를 넘어가는 명령어는 무시(-5 ~ 5)
// 캐릭터가 처음 걸어본 길의 길이를 구하자
class Solution {
    public int solution(String dirs) {
        int answer = 0;
        Set<String> s = new HashSet<>();
        int nowX = 0; int nowY = 0;
        
        for(int i=0;i<dirs.length();i++){
            int nx = nowX;
            int ny = nowY;
            String op = "";
            
            if(dirs.charAt(i) == 'L'){
                op = "R";
                nx--;
            }
            else if(dirs.charAt(i) == 'R'){
                op = "L";
                nx++;
            }
            else if(dirs.charAt(i) == 'U'){
                op = "D";
                ny++;
            }
            else {
                op = "U";
                ny--;
            }
            
            if(ny < -5 || nx < -5 || nx > 5 || ny > 5) continue;
            String check1 = op+nowX+nowY;
            String check2 = String.valueOf(dirs.charAt(i))+nx+ny;
            nowX = nx;
            nowY = ny;
            
            if(s.contains(check1) || s.contains(check2)) continue;
            s.add(check1);
            s.add(check2);
            answer++;

        }
        
        
        return answer;
    }
}
