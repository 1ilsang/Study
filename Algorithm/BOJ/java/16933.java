//https://www.acmicpc.net/problem/16933

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m, k;
    private final static int[] dc = {1, 0, -1, 0};
    private final static int[] dr = {0, 1, 0, -1};
    private static int[][] area;
    private static int[][][][] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        k = Integer.parseInt(tmp[2]);
        area = new int[n][m];
        chk = new int[n][m][k + 1][2];

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) area[i][j] = line[j] - '0';
        }
        System.out.println(bfs());
    }

    private static int bfs() {
        int ret = -1;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0, 1, k, 1));
        chk[0][0][k][1] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            int bn = queue.peek().bn;
            int t = queue.peek().t;
            int nt = (t + 1) % 2;
            queue.poll();

//            System.out.printf("%d, %d) p: %d, bn: %d, t: %d\n", r, c, p, bn, t);
            if (r == n - 1 && c == m - 1) {
                ret = p;
                break;
            }
            if (chk[r][c][bn][nt] == 0) {
                chk[r][c][bn][nt] = 1;
                queue.offer(new Node(r, c, p + 1, bn, nt));
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc][bn][t] == 1) continue;

                if (area[nr][nc] == 0 && chk[nr][nc][bn][nt] == 0) {
                    chk[nr][nc][bn][nt] = 1;
                    queue.offer(new Node(nr, nc, p + 1, bn, nt));
                }
                if (bn > 0 && area[nr][nc] == 1 && t == 1 && chk[nr][nc][bn-1][nt] == 0) {
                    chk[nr][nc][bn - 1][nt] = 1;
                    queue.offer(new Node(nr, nc, p + 1, bn - 1, nt));
                }
            }
        }
        return ret;
    }

    private static class Node {
        int r, c, p, bn, t;

        public Node(int r, int c, int p, int bn, int t) {
            this.r = r;
            this.c = c;
            this.p = p;
            this.bn = bn;
            this.t = t;
        }
    }
}
