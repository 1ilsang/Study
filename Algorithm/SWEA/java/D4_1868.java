//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    private static int n, ans;
    private final static int[] dr = {0, 1, 0, -1, -1, 1, 1, -1};
    private final static int[] dc = {1, 0, -1, 0, 1, 1, -1, -1};
    private static char[][] area;
    private static int[][] chk, chk2;
    private static Queue<Node> queue;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int tcase = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= tcase; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            queue = new LinkedList<>();
            area = new char[n][n];
            chk = new int[n][n];
            chk2 = new int[n][n];
            ans = 0;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                String line = st.nextToken();
                for (int j = 0; j < n; j++) {
                    area[i][j] = line.charAt(j);
                    if (area[i][j] == '.') queue.offer(new Node(i, j));
                }
            }
            bfs();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (chk[i][j] == 0 && area[i][j] == '.' && chk2[i][j] == 0) {
                        ans++;
                        bfs2(i, j);
                    }
                }
            }
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (chk[i][j] > 0) ans++;
            System.out.println("#" + t + " " + ans);
        }
    }

    private static void bfs() {
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int hit = 0;
            queue.poll();
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if (area[nr][nc] == '*') hit++;
            }
            chk[r][c] = hit;
        }
    }

    private static void bfs2(int sr, int sc) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc));
        chk2[sr][sc] = 1;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if (chk[nr][nc] == 0 && area[nr][nc] == '.' && chk2[nr][nc] == 0) {
                    chk2[nr][nc] = 1;
                    queue.offer(new Node(nr, nc));
                }
                chk[nr][nc] = 0;
                chk2[nr][nc] = 1;
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
