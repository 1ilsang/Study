//https://www.acmicpc.net/problem/1261

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area;
    private static int[][] chk;

    private static int bfs() {
        int ret = Integer.MAX_VALUE;
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.offer(new Node(0, 0, 0));
        chk[0][0] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            queue.poll();

            if(r == n - 1 && c == m - 1) {
                ret = p;
                break;
            }

            for(int i = 0 ; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1) continue;
                int tp = p;
                if(area[nr][nc] == 1) tp += 1;
                chk[nr][nc] = 1;
                queue.offer(new Node(nr, nc, tp));
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        m = Integer.parseInt(tmp[0]);
        n = Integer.parseInt(tmp[1]);
        area = new int[n][m];
        chk = new int[n][m];

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) area[i][j] = line[j] - '0';
        }
        System.out.println(bfs());
    }

    private static class Node implements Comparable<Node> {
        int r, c, p;

        public Node(int r, int c, int p) {
            this.r = r;
            this.c = c;
            this.p = p;
        }
        @Override
        public int compareTo(Node o) {
            return this.p - o.p;
        }
    }
}
