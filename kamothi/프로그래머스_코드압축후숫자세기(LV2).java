// 압축
// 분할 정복
// 4분할
import java.util.*;

class Solution {
    int[] answer = new int[]{0,0};
    public int[] solution(int[][] arr) {
        
       if(check(arr)){
            if(arr[0][0] == 0) answer[0]++;
            else answer[1]++;
        }
        else{
            quadTree(arr);
        }
        return answer;
    }
    
    // 4분할로 나누기
    public void quadTree(int[][] arr){
        int size = arr.length;
        
        if(size == 1){
            if(arr[0][0] == 0) answer[0]++;
            else answer[1]++;
            return;
        }
        
        int[][] arr1 = new int[size/2][size/2];
        int[][] arr2 = new int[size/2][size/2];
        int[][] arr3 = new int[size/2][size/2];
        int[][] arr4 = new int[size/2][size/2];
        
        // 분할하기
        int nx=0,ny=0;
        for(int i=0;i<size;i++){
            if(ny == size/2) ny =0;
            for(int j=0;j<size;j++){
                if(nx == size/2) nx =0;
                // 위쪽
                if(i < size/2){
                    if(j < size/2) arr1[ny][nx] = arr[i][j];
                    else arr2[ny][nx] = arr[i][j];
                }
                else{
                    if(j < size/2) arr3[ny][nx] = arr[i][j];
                    else arr4[ny][nx] = arr[i][j];
                }
                nx++;
            }
            ny++;
        }
        
        
        // 압축가능한지 체크하기
        List<int[][]> l = new ArrayList<>();
        l.add(arr1);
        l.add(arr2);
        l.add(arr3);
        l.add(arr4);
        
        for(int[][] tmp : l){
            if(check(tmp)){
                if(tmp[0][0] == 0) answer[0]++;
                else answer[1]++;
            }
            else{
                quadTree(tmp);
            }
        }
        return;
    }
    
    
    public boolean check(int[][] arr){
        int tmp = arr[0][0];
        boolean flag = true;
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length;j++){
                if(tmp != arr[i][j]) flag = false;
            }
        }
        
        return flag;
    }
}
