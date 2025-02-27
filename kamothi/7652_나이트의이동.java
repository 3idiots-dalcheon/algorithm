import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_7652 {
    static int t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};

        while(t > 0){
            t--;
            int n;
            Position start;
            Position dest;

            n = Integer.parseInt(br.readLine());
            boolean[][] visited = new boolean[n][n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            start = new Position(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),0);

            st = new StringTokenizer(br.readLine());
            dest = new Position(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),0);

            Queue<Position> q = new LinkedList<>();
            q.add(start);
            visited[start.x][start.y] = true;


            while(!q.isEmpty()){
                Position now = q.poll();

                if(now.x == dest.x && now.y == dest.y){
                    System.out.println(now.cnt);
                    break;
                }

                for(int i=0;i<8;i++){
                    int nx = dx[i] + now.x;
                    int ny = dy[i] + now.y;

                    if(nx < 0 || ny < 0 || nx >= n || ny >=n){
                        continue;
                    }

                    if(visited[nx][ny]) continue;

                    q.add(new Position(nx,ny, now.cnt+1));
                    visited[nx][ny] = true;
                }
            }


        }
    }
    static class Position{
        int x;
        int y;
        int cnt;
        Position(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}
