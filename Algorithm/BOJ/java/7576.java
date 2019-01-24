//https://www.acmicpc.net/problem/7576

import java.io.*;
import java.util.*;

public class Main {
    private static class Node {
        int r, c, p;

        public Node(int r, int c, int p) {
            this.r = r;
            this.c = c;
            this.p = p;
        }
    }

    private static int M, N, total;
    private static int[][] area, chk;
    private static int dr[] = {0, 1, 0, -1};
    private static int dc[] = {1, 0, -1, 0};
    private static Queue<Node> q = new LinkedList<>();

    private static int bfs() {
        int ret = 0;
        int cnt = 0;
        while (!q.isEmpty()) {
            int r = q.peek().r;
            int c = q.peek().c;
            int p = q.peek().p;
            q.poll();
            cnt++;
            ret = Math.max(ret, p);
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < N && nc < M && area[nr][nc] == 0 && chk[nr][nc] == 0) {
                    chk[nr][nc] = 1;
                    q.offer(new Node(nr, nc, p + 1));
                }
            }
        }

        return total == cnt ? ret : -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] tmp = br.readLine().split(" ");
        M = Integer.parseInt(tmp[0]);
        N = Integer.parseInt(tmp[1]);
        area = new int[N][M];
        chk = new int[N][M];
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                area[i][j] = Integer.parseInt(tmp[j]);
                if (area[i][j] == -1) continue;
                else if (area[i][j] == 1) q.offer(new Node(i, j, 0));
                total++;
            }
        }
        System.out.println(bfs());
    }
}
