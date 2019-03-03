//https://www.acmicpc.net/problem/16957

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static int[][] area, chk;
    private static int[] dr = {0, 1, 0, -1, -1, 1, 1, -1};
    private static int[] dc = {1, 0, -1, 0, 1, 1, -1, -1};
    private static PriorityQueue<Node> queue;

    private static void bfs() {
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int now = queue.peek().d;
            queue.poll();
            if(chk[r][c] == 0) continue;

            int nnr = -1;
            int nnc = -1;
            int tmp = now;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || area[nr][nc] > area[r][c]) continue;
                if (tmp > area[nr][nc]) {
                    tmp = area[nr][nc];
                    nnr = nr;
                    nnc = nc;
                }
            }
            if (nnr != -1) {
                chk[nnr][nnc] += chk[r][c];
                chk[r][c] = 0;
                queue.offer(new Node(nnr, nnc, area[nnr][nnc]));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        queue = new PriorityQueue<>();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        chk = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
                queue.offer(new Node(i, j, area[i][j]));
                chk[i][j] = 1;
            }
        }
        bfs();
        print();
    }

    private static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) System.out.print(chk[i][j] + " ");
            System.out.println();
        }
    }

    private static class Node implements Comparable<Node> {
        int r, c, d;

        public Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }

        @Override
        public int compareTo(Node o) {
            return o.d - this.d;
        }
    }
}
