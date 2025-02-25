import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class boj_2644 {
    static boolean[] visited = new boolean[101];
    static int result = 0;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int x,y;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());


        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        int m = Integer.parseInt(br.readLine());

        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }

        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        bfs(x);

        if(result == 0) System.out.println(-1);
        else System.out.println(result);

    }

    public static void bfs(int start){
        Queue<AbstractMap.SimpleEntry<Integer, Integer>> q = new LinkedList<>();
        q.add(new AbstractMap.SimpleEntry<>(start, 0));
        visited[start] = true;

        while(!q.isEmpty()){
            AbstractMap.SimpleEntry<Integer, Integer> entry = q.poll();
            int node = entry.getKey();
            int cnt = entry.getValue();

            if(node == y){
                result = cnt;
                return;
            }

            for (int next : graph.get(node)) {
                if (!visited[next]) {
                    q.add(new AbstractMap.SimpleEntry<>(next,cnt+1));
                    visited[next] = true;
                }
            }
        }
    }
}
