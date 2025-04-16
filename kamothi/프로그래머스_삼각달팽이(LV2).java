import java.util.*;

// n = 1000, 높이가 n까지 배열 채우기
// 방향 이동(위쪽, 오른쪽, 왼쪽 위)
class Solution {
    public int[] solution(int n) {
        int[] dx = {1,0,-1};
        int[] dy = {0,1,-1};
        
        int maxVal = n*(n+1)/2;
        int[] answer = new int[maxVal];
        int[][] arr = new int[n][n];
        int next = 1;
        int d = 0;
        int x = 0, y = 0;
        
        while(true){
            arr[x][y] = next++;
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx == n|| ny == n || nx == -1 || ny == -1 || arr[nx][ny] != 0){
                d = (d+1) % 3;
            }
            
            nx = x + dx[d];
            ny = y + dy[d];
            
            x = nx;
            y = ny;

            if (next == maxVal+1) break;
        }
        
        int now = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                answer[now++] = arr[i][j];
            }
        }
        
        return answer;
    }
}
