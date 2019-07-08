//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD&categoryId=AV15QRX6APsCFAYD&categoryType=CODE&&&
//http://1ilsang.blog.me/221580614584

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Main {
    private static final int INF = 999999999;
    private static int n;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area, dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < tcase; t++) {
            n = Integer.parseInt(br.readLine().trim());
            area = new int[n][n];
            dist = new int[n][n];

            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < n; j++) {
                    area[i][j] = str.charAt(j) - '0';
                    dist[i][j] = INF;
                }
            }

            System.out.printf("#%d %d\n", t + 1, go());
        }
    }

    private static int go() {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0, 0));

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int nowCost = queue.peek().cost;
            queue.poll();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                int nextCost = nowCost + area[nr][nc];
                if (nextCost >= dist[nr][nc]) continue;
                dist[nr][nc] = nextCost;
                queue.offer(new Node(nr, nc, nextCost));
            }

        }

        return dist[n - 1][n - 1];
    }

    private static class Node {
        int r, c, cost;

        public Node(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }
    }
}
