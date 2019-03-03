//https://www.acmicpc.net/problem/16958

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, t;
    private static Node[] nodes;
    private static int[][] distL;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        nodes = new Node[n + 1];
        distL = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            nodes[i] = new Node(s, x, y);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                int tel = Integer.MAX_VALUE;
                if (nodes[i].s == 1 && nodes[j].s == 1) tel = t;
                distL[i][j] = Math.min(Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y), tel);
            }
        }

        st = new StringTokenizer(br.readLine());
        int tcase = Integer.parseInt(st.nextToken());
        for (int i = 0; i < tcase; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            System.out.println(dijkstra(a, b));
        }
    }

    private static int dijkstra(int strt, int end) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.offer(new Node(strt, 0));
        dist[strt] = 0;

        while (!queue.isEmpty()) {
            int now = queue.peek().now;
            int nowCost = queue.peek().dist;
            queue.poll();
            if(nowCost > dist[now]) continue;

            for (int i = 1; i <= n; i++) {
                if (i == now) continue;
                if(dist[i] > nowCost + distL[now][i]) {
                    dist[i] = nowCost + distL[now][i];
                    queue.offer(new Node(i, dist[i]));
                }
            }
        }
        return dist[end];
    }

    private static class Node implements Comparable<Node>{
        int s, x, y, now, dist;

        public Node(int now, int dist) {
            this.now = now;
            this.dist = dist;
        }

        public Node(int s, int x, int y) {
            this.s = s;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Node o) {
            return this.dist - o.dist;
        }
    }
}
