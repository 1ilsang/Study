import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static int[] dr = {0, 1, 0, -1};
    public static int[] dc = {1, 0, -1, 0};
    public static int n, m;
    public static int[][] area;
    public static int[][] chk;

    public static class Pair {
        int r, c, p;

        public Pair(int r, int c, int p) {
            this.r = r;
            this.c = c;
            this.p = p;
        }
    }

    public static int bfs(int sr, int sc) {
        int ret = 0;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(sr, sc, 0));

        while (!q.isEmpty()) {
            int r = q.peek().r;
            int c = q.peek().c;
            int p = q.peek().p;
            q.poll();
            if (p > ret) ret = p;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && chk[nr][nc] == 0 && area[nr][nc] == 1) {
                    chk[nr][nc] = 1;
                    q.offer(new Pair(nr, nc, p + 1));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                chk[i][j] = 0;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        int ans = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);
        area = new int[n][m];
        chk = new int[n][m];

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                if (line[j] == 'L') area[i][j] = 1;
                else area[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 1) ans = Math.max(ans, bfs(i, j));
            }
        }

        System.out.println(ans);
    }
}
