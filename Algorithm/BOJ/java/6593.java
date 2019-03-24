//https://www.acmicpc.net/problem/6593
//http://1ilsang.blog.me/221496156548

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int l, r, c;
    private static int[] dr = {1, 0, -1, 0};
    private static int[] dc = {0, 1, 0, -1};
    private static char[][][] area;
    private static int[][][] chk;
    private static Queue<Node> queue;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String[] tmp = br.readLine().split(" ");
            l = Integer.parseInt(tmp[0]);
            r = Integer.parseInt(tmp[1]);
            c = Integer.parseInt(tmp[2]);
            if (l == 0 && r == 0 && c == 0) break;
            queue = new LinkedList<>();
            area = new char[l][r][c];
            chk = new int[l][r][c];
            for (int i = l - 1; i >= 0; i--) {
                for (int j = 0; j < r; j++) {
                    char[] charTmp = br.readLine().toCharArray();
                    for (int z = 0; z < c; z++) {
                        area[i][j][z] = charTmp[z];
                        if (area[i][j][z] == 'S') {
                            queue.offer(new Node(i, j, z, 0));
                            chk[i][j][z] = 1;
                        }
                    }
                }
                br.readLine();
            }
            int ret = bfs();
            if (ret == -1) System.out.println("Trapped!");
            else System.out.printf("Escaped in %d minute(s).\n", ret);
        }
    }

    private static int bfs() {
        int ret = -1;

        while (!queue.isEmpty()) {
            int nowl = queue.peek().l;
            int nowr = queue.peek().r;
            int nowc = queue.peek().c;
            int p = queue.peek().p;
            queue.poll();

            if (area[nowl][nowr][nowc] == 'E') {
                ret = p;
                break;
            }
            
            if (nowl > 0 && chk[nowl - 1][nowr][nowc] == 0 && area[nowl - 1][nowr][nowc] != '#') {
                chk[nowl - 1][nowr][nowc] = 1;
                queue.offer(new Node(nowl - 1, nowr, nowc, p + 1));
            }
            if (nowl + 1 < l && chk[nowl + 1][nowr][nowc] == 0 && area[nowl + 1][nowr][nowc] != '#') {
                chk[nowl + 1][nowr][nowc] = 1;
                queue.offer(new Node(nowl + 1, nowr, nowc, p + 1));
            }
            for (int i = 0; i < 4; i++) {
                int nr = nowr + dr[i];
                int nc = nowc + dc[i];
                if (nr < r && nc < c && nr >= 0 && nc >= 0 && area[nowl][nr][nc] != '#' && chk[nowl][nr][nc] == 0) {
                    chk[nowl][nr][nc] = 1;
                    queue.offer(new Node(nowl, nr, nc, p + 1));
                }
            }
        }

        return ret;
    }

    private static class Node {
        int l, r, c, p;

        private Node(int l, int r, int c, int p) {
            this.l = l;
            this.r = r;
            this.c = c;
            this.p = p;
        }
    }
}
