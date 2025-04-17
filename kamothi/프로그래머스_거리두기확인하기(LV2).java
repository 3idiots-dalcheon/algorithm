import java.util.*;


class Solution {
    boolean flag;
    
    public int[] solution(String[][] places) {
        int size = places.length;
        int now = 0;
        int[] answer = new int[size];
        
        while(now < size){
            List<int[]> list = new ArrayList<>();
            flag = true;
            
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(places[now][i].charAt(j) == 'P'){
                        list.add(new int[]{i,j});
                    }
                }
            }
            
            for(int i=0;i<list.size();i++){
                for(int j=i+1;j<list.size();j++){
                    if(!check(list.get(i)[0],list.get(i)[1],list.get(j)[0],list.get(j)[1],places[now])){
                        flag = false;
                        break;
                    }
                }
            }
            
            if(flag) answer[now] = 1;
            else answer[now] = 0;
            
            now++;
        }
        
        return answer;
    }
    
    public boolean check(int x1, int y1, int x2, int y2, String[] places){
        int dist = Math.abs(x1 - x2) + Math.abs(y1 - y2);
        
        if(dist <= 2){
            if(dist == 1) return false;
            else{
                // 같은 행
                if(x1 == x2){
                    int mid;
                    if(y1 > y2) mid = y1 - 1;
                    else mid = y2 - 1;
                    
                    if(places[x1].charAt(mid) == 'X') return true;
                    else return false;
                }
                
                // 같은 열
                else if(y1 == y2){
                    int mid;
                    if(x1 > x2) mid = x1 - 1;
                    else mid = x2 - 1;
                    
                    if(places[mid].charAt(y1) == 'X') return true;
                    else return false;
                }
                
                // 대각선
                else{
                    if(places[x1].charAt(y2) == 'X' && places[x2].charAt(y1) == 'X') return true;
                    else return false;
                }
                
            }
        }else{
            return true;
        }
    }
}
