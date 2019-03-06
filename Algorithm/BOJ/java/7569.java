//https://www.acmicpc.net/problem/7569

import java.util.*;

public class Main {
    private static int n, m, hh;
    private final static int[] dh = {1, -1};
    private final static int[] dr = {0, 1, 0, -1};
    private final static int[] dc = {1, 0, -1, 0};
    private static int[][][] area, chk;
    private static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        hh = sc.nextInt();
        area = new int[n][m][hh];
        chk = new int[n][m][hh];
        int cnt = 0;

        for (int ii = 0; ii < hh; ii++)
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
                area[i][j][ii] = sc.nextInt();
                if(area[i][j][ii] == 1) {
                    chk[i][j][ii] = 1;
                    queue.offer(new Node(i,j,ii,0));
                }
            }
        int ans = bfs();
        for (int ii = 0; ii < hh; ii++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (area[i][j][ii] == 0 && chk[i][j][ii] == 0) cnt = -1;
        System.out.println(cnt < 0 ? -1 : ans);
    }

    private static int bfs() {
        int ret = 0;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int h = queue.peek().h;
            int p = queue.peek().p;
            queue.poll();
            ret = Math.max(ret, p);

            for (int i = 0; i < 2; i++) {
                int nh = h + dh[i];
                if (nh < 0 || nh >= hh || area[r][c][nh] != 0 || chk[r][c][nh] == 1) continue;
                chk[r][c][nh] = 1;
                queue.offer(new Node(r, c, nh, p + 1));
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc][h] == 1 || area[nr][nc][h] != 0) continue;
                chk[nr][nc][h] = 1;
                queue.offer(new Node(nr, nc, h, p + 1));
            }
        }
        return ret;
    }

    private static class Node {
        int r, c, h, p;

        public Node(int r, int c, int h, int p) {
            this.r = r;
            this.c = c;
            this.h = h;
            this.p = p;
        }
    }
}
