//https://www.acmicpc.net/problem/2638

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static int n, m;
    private static int[][] area;
    private static int[][] fireChk, outerAir, chk;
    private final static int[] dr = {0, 1, 0, -1};
    private final static int[] dc = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        fireChk = new int[n][m];
        outerAir = new int[n][m];
        chk = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) area[i][j] = Integer.parseInt(st.nextToken());
        }

        int cnt = 0;
        while (true) {
            boolean flag = true;
            chkAir();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (area[i][j] == 1 && chk[i][j] == 0) {
                        flag = false;
                        bfs(i, j);
                    }
                }
            }
            if (flag) break;
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) chk[i][j] = 0;
            fire();
            cnt++;
        }
        System.out.println(cnt);
    }

    private static void chkAir() {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) outerAir[i][j] = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0));
        outerAir[0][0] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
//            System.out.println(r+","+c);
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || area[nr][nc] == 1 || outerAir[nr][nc] == 1) continue;
                outerAir[nr][nc] = 1;
                queue.offer(new Node(nr, nc));
            }
        }
    }

    private static void bfs(int sr, int sc) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc));
        chk[sr][sc] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int hit = 0;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (area[nr][nc] == 0 && outerAir[nr][nc] == 1) hit++;
                else if (chk[nr][nc] == 0 && area[nr][nc] == 1) {
                    chk[nr][nc] = 1;
                    queue.offer(new Node(nr, nc));
                }
            }
            if (hit > 1) fireChk[r][c] = 1;
        }
    }

    private static void fire() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (fireChk[i][j] == 1) {
                    area[i][j] = 0;
                    fireChk[i][j] = 0;
                }
            }
        }
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
