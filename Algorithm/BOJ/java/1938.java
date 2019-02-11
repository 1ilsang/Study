//https://www.acmicpc.net/problem/1938
//http://1ilsang.blog.me/221462911169

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private final static int dr[] = {0, 1, 0, -1, -1, 1, 1, -1};
    private final static int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
    private static int n;
    private static char[][] area;
    private static int[][][] chk;

    private static class Node {
        int r, c, p, d;

        public Node(int r, int c, int p, int d) {
            this.r = r;
            this.c = c;
            this.p = p;
            this.d = d;
        }
    }

    // 0 = 가로, 1 = 세로
    private static int bfs(int sr, int sc, int sd) {
        int ret = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc, 0, sd));
        chk[sr][sc][sd] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            int d = queue.peek().d;
            queue.poll();

            if ((d == 0 && c - 1 >= 0 && c + 1 < n && area[r][c] == 'E' && area[r][c - 1] == 'E' && area[r][c + 1] == 'E')
                    || (d == 1 && r - 1 >= 0 && r + 1 < n && area[r - 1][c] == 'E' && area[r][c] == 'E' && area[r + 1][c] == 'E')) {
                ret = p;
                break;
            }

            // isRotate?
            boolean isRotate = true;
            int nd = (d + 1) % 2;
            if (chk[r][c][nd] == 0) {
                for (int j = 0; j < 8; j++) {
                    int ndr = r + dr[j];
                    int ndc = c + dc[j];
                    if (ndr < 0 || ndc < 0 || ndr >= n || ndc >= n || area[ndr][ndc] == '1') {
                        isRotate = false;
                        break;
                    }
                }
            }
            if (isRotate && chk[r][c][nd] == 0) {
                chk[r][c][nd] = 1;
                queue.offer(new Node(r, c, p + 1, nd));
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n || area[nr][nc] == '1' || chk[nr][nc][d] == 1) continue;

                if (d == 0) {
                    if (nc - 1 >= 0 && nc + 1 < n && area[nr][nc + 1] != '1' && area[nr][nc - 1] != '1') {
                        chk[nr][nc][d] = 1;
                        queue.offer(new Node(nr, nc, p + 1, d));
                    }
                } else if (d == 1) {
                    if (nr - 1 >= 0 && nr + 1 < n && area[nr + 1][nc] != '1' && area[nr - 1][nc] != '1') {
                        chk[nr][nc][d] = 1;
                        queue.offer(new Node(nr, nc, p + 1, d));
                    }
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        area = new char[n][n];
        chk = new int[n][n][2];
        int sr = 0, sc = 0, d = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                area[i][j] = line[j];
                if (area[i][j] == 'B') {
                    if (flag == 1) {
                        sr = i;
                        sc = j;
                        if (j > 0 && area[i][j - 1] == 'B') d = 0;
                        else d = 1;
                        flag++;
                    } else flag++;
                }
            }
        }
        if (d == 0) {
            area[sr][sc] = '0';
            area[sr][sc - 1] = '0';
            area[sr][sc + 1] = '0';
        } else {
            area[sr][sc] = '0';
            area[sr + 1][sc] = '0';
            area[sr - 1][sc] = '0';
        }
        System.out.println(bfs(sr, sc, d));
    }
}
