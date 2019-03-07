//https://www.acmicpc.net/problem/2636

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area, chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int time = 0;
        int ch = 0;

        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new int[n][m];
        for (int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(tmp[j]);
                if(area[i][j] == 1) ch++;
            }
        }
        while (true) {
            int tmpN;
            if ((tmpN = go()) == 0) break;
            time++;
            ch = tmpN;
        }
        System.out.printf("%d\n%d\n", time + 1, ch);
    }

    private static int go() {
        int ret = 0;
        chk = new int[n][m];
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0));
        chk[0][0] = 1;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1) continue;
                chk[nr][nc] = 1;
                if (area[nr][nc] == 0) queue.offer(new Node(nr, nc));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(area[i][j] == 1 && chk[i][j] == 1) area[i][j] = 0;
                if(area[i][j] == 1) ret++;
            }
        }
        return ret;
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
