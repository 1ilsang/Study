//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18LoAqItcCFAZN

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    private static int n;
    private final static int[] dr = {0, 1, 0, -1};
    private final static int[] dc = {1, 0, -1, 0};
    private static int[][] area, chk;
    private static LinkedList<Node> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int tcase = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= tcase; t++) {
            list = new LinkedList<>();
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            area = new int[n][n];
            chk = new int[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) area[i][j] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (chk[i][j] == 0 && area[i][j] > 0) bfs(i, j);
            Collections.sort(list);

            System.out.printf("#%d %d", t, list.size());
            for (int i = 0; i < list.size(); i++) System.out.printf(" %d %d", list.get(i).r, list.get(i).c);
            System.out.println();
        }
    }

    private static void bfs(int sr, int sc) {
        int[][] boxChk = new int[n][n];
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc, -1));
        chk[sr][sc] = 1;
        boxChk[sr][sc] = 1;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n || area[nr][nc] == 0 || boxChk[nr][nc] == 1) continue;
                chk[nr][nc] = 1;
                boxChk[nr][nc] = 1;
                queue.offer(new Node(nr, nc, -1));
            }
        }
        setBoxSize(boxChk);
    }

    private static void setBoxSize(int[][] boxChk) {
        int lr = -1, lc = -1, rr = -1, rc = -1;
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boxChk[i][j] == 1) {
                    if (flag) {
                        flag = false;
                        lr = i;
                        lc = j;
                    }
                    if (rr < i) rr = i;
                    if (rc < j) rc = j;
                }
            }
        }
        rr -= lr;
        rc -= lc;
        rr++;
        rc++;
        list.add(new Node(rr, rc, rr * rc));
    }

    private static class Node implements Comparable<Node> {
        int r, c, d;

        public Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d= d;
        }

        @Override
        public int compareTo(Node o) {
            if(this.d == o.d) return this.r - o.r;
            return this.d - o.d;
        }
    }
}
