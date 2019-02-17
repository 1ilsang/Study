//https://www.acmicpc.net/problem/2573

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    private static int n, m, cnt;
    private static int[][] area, meltChk, chk;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new int[n][m];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(tmp[j]);
                if (area[i][j] > 0) cnt++;
            }
        }
        while (true) {
            boolean flag = false;
            meltChk = new int[n][m];
            chk = new int[n][m];
//            System.out.println("=============== " + cnt);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (area[i][j] > 0 && chk[i][j] == 0) {
                        int tmpNum = bfs(i, j);
                        if (tmpNum != cnt) {
                            System.out.println(ans);
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (area[i][j] == 0 && meltChk[i][j] == 0) meltIce(i, j);
                }
            if (cnt == 0) {
                System.out.println(0);
                break;
            }
            ans++;
        }
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    private static void meltIce(int sr, int sc) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc));
        meltChk[sr][sc] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || meltChk[nr][nc] == 1) continue;

                if (area[nr][nc] > 0) {
                    area[nr][nc] -= 1;
                    if(area[nr][nc] == 0) {
                        cnt--;
                        meltChk[nr][nc] = 1;
                    }
                }
                else {
                    meltChk[nr][nc] = 1;
                    queue.offer(new Node(nr, nc));
                }
            }
        }
//        System.out.println("melt: " + sr + ", " + sc + ": " + cnt);
    }

    private static int bfs(int sr, int sc) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc));
        chk[sr][sc] = 1;
        int ret = 1;

        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();

            for(int i = 0 ; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1 || area[nr][nc] == 0) continue;
                chk[nr][nc] = 1;
                ret++;
                queue.offer(new Node(nr, nc));
            }
        }
//        System.out.println(sr + ", " + sc + ": " + ret);
        return ret;
    }
}
