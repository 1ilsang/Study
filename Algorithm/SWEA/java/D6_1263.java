//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18P2B6Iu8CFAZN
//http://1ilsang.blog.me/221476247458

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    private static int n;
    private static int[][] area;

    private static class Node implements Comparable<Node> {
        int n, p;

        public Node(int n, int p) {
            this.n = n;
            this.p = p;
        }

        @Override
        public int compareTo(Node o) {
            return this.p - o.p;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int t = 1; t <= tcase; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            area = new int[n][n];
            int r = 0;
            while (st.hasMoreTokens()) {
                for (int j = 0; j < n; j++) area[r][j] = Integer.parseInt(st.nextToken());
                r++;
            }
            int ans = Integer.MAX_VALUE;
            for(int i = 0 ; i < n; i++) ans = Math.min(dijkstra(i), ans);
            System.out.printf("#%d %d\n", t, ans);
        }
    }

    private static int dijkstra(int cur) {
        int[] dist = new int[n];
        for(int i = 0 ; i < n; i++) dist[i] = 1000;
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
        priorityQueue.offer(new Node(cur, 0));
        dist[cur] = 0;

        while(!priorityQueue.isEmpty()) {
            int now = priorityQueue.peek().n;
            int cost = priorityQueue.peek().p;
            priorityQueue.poll();
            if(cost > dist[now]) continue;

            for(int i = 0 ; i < n; i++) {
                if(area[now][i] == 1) {
                    int next = i;
                    int nextCost = area[now][i];
                    if(dist[next] > cost + nextCost) {
                        dist[next] = cost + nextCost;
                        priorityQueue.offer(new Node(next, dist[next]));
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0 ; i < n; i++) ret += dist[i];
        return ret;
    }
}
