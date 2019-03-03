//https://www.acmicpc.net/problem/5427

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static char[][] area;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static LinkedList<Node> fireList;
    private static Node start;

    private static int bfs() {
        int ret = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(start);
        for (Node e : fireList) queue.offer(e);
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            int d = area[r][c] == '@' ? 0 : 1;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (d == 0) {
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                        ret = p + 1;
                        break;
                    }
                    if (area[nr][nc] == '.') {
                        area[nr][nc] = '@';
                        queue.offer(new Node(nr, nc, p + 1));
                    }
                } else {
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || area[nr][nc] == '*' || area[nr][nc] == '#') continue;
                    area[nr][nc] = '*';
                    queue.offer(new Node(nr, nc));
                }
            }
            if (ret > 0) break;
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        while (tcase-- > 0) {
            String[] tmp = br.readLine().split(" ");
            m = Integer.parseInt(tmp[0]);
            n = Integer.parseInt(tmp[1]);
            area = new char[n][m];
            fireList = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                char[] tmp2 = br.readLine().toCharArray();
                for (int j = 0; j < m; j++) {
                    area[i][j] = tmp2[j];
                    if (area[i][j] == '*') fireList.add(new Node(i, j));
                    else if (area[i][j] == '@') start = new Node(i, j, 0);
                }
            }
            int ret = bfs();
            if (ret == 0) System.out.println("IMPOSSIBLE");
            else System.out.println(ret);
        }
    }

    private static class Node {
        int r, c, p;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public Node(int r, int c, int p) {
            this(r, c);
            this.p = p;
        }
    }
}
