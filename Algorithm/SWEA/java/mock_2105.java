import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    private static int n, ans;
    private static int[][] area;
    private static boolean[] chk;
    private static int[] dr = {-1, 1, 1, -1};
    private static int[] dc = {1, 1, -1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int tcase = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= tcase; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            area = new int[n][n];
            chk = new boolean[101];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) area[i][j] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dfs(i, j, i, j, 0, 1);

            System.out.printf("#%d %d\n", t, ans < 4 ? -1 : ans);
            ans = 0;
        }
    }

    private static void dfs(int sr, int sc, int r, int c, int d, int p) {
        chk[area[r][c]] = true;
        for (int i = d; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr == sr && sc == nc) ans = Math.max(ans, p);
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || chk[area[nr][nc]]) continue;
            dfs(sr, sc, nr, nc, i, p + 1);
        }
        chk[area[r][c]] = false;
    }
}
