//https://www.acmicpc.net/problem/1516
//http://1ilsang.blog.me/221516936340

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        LinkedList<Integer>[] list = new LinkedList[n + 1];
        Queue<Integer> queue = new LinkedList<>();
        int[] time = new int[501];
        int[] inDegree = new int[501];
        int[] ans = new int[501];

        for(int i = 0 ; i <= n; i++) list[i] = new LinkedList<>();
        for(int i = 1 ; i <= n; i++) {
            String[] tmp = br.readLine().split(" ");
            time[i] = Integer.parseInt(tmp[0]);
            for(int j = 1 ; j < tmp.length; j++) {
                int now = Integer.parseInt(tmp[j]);
                if(now == -1) break;
                inDegree[i]++;
                list[now].push(i);
            }
            if(inDegree[i] == 0) {
                ans[i] = time[i];
                queue.offer(i);
            }
        }

        for(int i = 1; i <= n; i++) {
            int cur = queue.poll();
            for(Integer next: list[cur]) {
                ans[next] = Math.max(ans[next], ans[cur] + time[next]);
                if(--inDegree[next] == 0) queue.offer(next);
            }
        }

        for(int i = 1; i <= n; i++) System.out.println(ans[i]);
    }
}
