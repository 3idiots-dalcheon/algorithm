import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 그림의 갯수와 가장 큰 넓이 구하기
public class boj_1926 {
    static int n,m;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static int answer1 = 0, answer2 = 0, tmp =0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(map[i][j] == 1 && !visited[i][j]){
                   tmp = 1;
                   answer1++;
                   dfs(i,j);

                   answer2 = Math.max(tmp,answer2);
               }
            }
        }

        System.out.println(answer1);
        System.out.println(answer2);
    }

    static void dfs(int x, int y){
        visited[x][y] = true;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check(nx,ny) && !visited[nx][ny] && map[nx][ny] == 1){
                tmp++;
                dfs(nx,ny);
            }
        }


    }

    static boolean check(int x, int y){
        if(x >= 0 && x < n && y >= 0 && y <m) return true;
        return false;
    }
}
