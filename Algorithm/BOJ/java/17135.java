//https://www.acmicpc.net/problem/17135
//https://1ilsang.blog.me/221572128543

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int n, m, d;
    private static boolean[] visit;
    private static LinkedList<Integer> archers = new LinkedList<>();
    private static int[] dr = {0, -1, 0};
    private static int[] dc = {-1, 0, 1};
    private static int[][] area;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        d = Integer.parseInt(str[2]);
        visit = new boolean[m];
        area = new int[n][m];

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) area[i][j] = Integer.parseInt(str[j]);
        }

        System.out.println(go(0, 0));
    }

    private static int go(int lo, int depth) {
        int ret = 0;
        if (depth == 3) return killThemAll();

        for (int i = lo; i < m; i++) {
            if (visit[i]) continue;
            visit[i] = true;
            archers.add(i);
            int inRet = go(i + 1, depth + 1);
            ret = inRet > ret ? inRet : ret;
            archers.pollLast();
            visit[i] = false;
        }
        return ret;
    }

    private static int killThemAll() {
        int[][] copy = new int[n][m];

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) copy[i][j] = area[i][j];
        int ret = 0;
        boolean isExist = true;

        while (isExist) {
            Queue<Node> hit = new LinkedList<>();

            isExist = false;
            for (Integer e : archers) {
                Queue<Node> archerFields = new LinkedList<>();
                boolean[][] archerVisit = new boolean[n][m];
                boolean flag = false;
                archerFields.add(new Node(n, e, 0));

                while (!archerFields.isEmpty()) {
                    int r = archerFields.peek().r;
                    int c = archerFields.peek().c;
                    int ad = archerFields.peek().d;
                    archerFields.poll();

                    for (int nd = 0; nd < 3; nd++) {
                        int nr = r + dr[nd];
                        int nc = c + dc[nd];
                        if (nr < 0 || nc < 0 || nr >= n || nc >= m || ad + 1 > d || archerVisit[nr][nc]) continue;

                        if (copy[nr][nc] == 0) {
                            archerFields.add(new Node(nr, nc, ad + 1));
                            archerVisit[nr][nc] = true;
                        } else {
                            hit.add(new Node(nr, nc));
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }

            for (Node e : hit) {
                if (copy[e.r][e.c] == 0) continue;
                copy[e.r][e.c] = 0;
                ret++;
            }

            for (int i = 0; i < m; i++) {
                for (int j = n - 1; j > 0; j--) {
                    copy[j][i] = copy[j - 1][i];
                    if (copy[j][i] == 1) isExist = true;
                }
                copy[0][i] = 0;
            }
        }

        return ret;
    }

    private static class Node {
        int r, c, d;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
}
