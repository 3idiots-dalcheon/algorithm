import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            Queue<int[]> queue = new LinkedList<>();
            PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());

            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                int priority = Integer.parseInt(st.nextToken());
                queue.add(new int[]{priority, i});
                priorityQueue.add(priority);
            }

            if(N == 0) {
                System.out.println(1);
                continue;
            }

            int cnt = 0;

            while(!queue.isEmpty()){
                int[] current = queue.poll();
                if(current[0] == priorityQueue.peek()){
                    priorityQueue.poll();
                    cnt++;
                    if (current[1] == M) {
                        System.out.println(cnt);
                        break;
                    }
                }
                else {
                    queue.add(current);
                }
            }



        }


    }
}
