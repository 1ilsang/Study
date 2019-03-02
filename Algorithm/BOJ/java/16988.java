//https://www.acmicpc.net/problem/16988

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static LinkedList<Node> list;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area, chk;

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    private static int bfs(Node e) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(e);
        chk[e.r][e.c] = 1;
        boolean flag = false;
        int ret = 0;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            ret++;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1 || area[nr][nc] == 1) continue;
                if (area[nr][nc] == 0) flag = true;
                chk[nr][nc] = 1;
                queue.offer(new Node(nr, nc));
            }
        }
        return flag ? 0 : ret;
    }

    private static int go(int lo) {
        int ret = 0;
        if (lo == 2) {
            int innerRet = 0;
            chk = new int[n][m];
            for (Node e : list) if (chk[e.r][e.c] == 0) innerRet += bfs(e);
            return innerRet;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 0) {
                    area[i][j] = 1;
                    ret = Math.max(ret, go(lo + 1));
                    area[i][j] = 0;
                }
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        list = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
                if (area[i][j] == 2) list.add(new Node(i, j));
            }
        }

        System.out.println(go(0));
    }
}
