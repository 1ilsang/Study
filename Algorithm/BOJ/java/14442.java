//https://www.acmicpc.net/problem/14442

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m, k;
    private final static int[] dr = {0, 1, 0, -1};
    private final static int[] dc = {1, 0, -1, 0};
    private static int[][] area;
    private static int[][][] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        k = Integer.parseInt(tmp[2]);
        area = new int[n][m];
        chk = new int[n][m][k + 1];

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) area[i][j] = line[j] - '0';
        }
        System.out.println(bfs());
    }

    private static int bfs() {
        int ret = -1;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0, 1, k));
        chk[0][0][k] = 1;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            int bn = queue.peek().bn;
            queue.poll();
            if (r == n - 1 && c == m - 1) {
                ret = p;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc][bn] == 1) continue;

                chk[nr][nc][bn] = 1;
                if (area[nr][nc] == 0) queue.offer(new Node(nr, nc, p + 1, bn));
                if (bn > 0 && area[nr][nc] == 1) {
                    chk[nr][nc][bn - 1] = 1;
                    queue.offer(new Node(nr, nc, p + 1, bn - 1));
                }
            }
        }
        return ret;
    }

    private static class Node {
        int r, c, p, bn;

        public Node(int r, int c, int p, int bn) {
            this.r = r;
            this.c = c;
            this.p = p;
            this.bn = bn;
        }
    }
}
