//https://www.acmicpc.net/problem/3184

import java.io.*;

public class Main {
    private static int n, m, v, o, av, ao;
    private static char[][] area;
    private static int[][] chk;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};

    private static void go(int r, int c) {
        chk[r][c] = 1;
        if (area[r][c] == 'v') v++;
        else if (area[r][c] == 'o') o++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && area[nr][nc] != '#' && chk[nr][nc] == 0) {
                go(nr, nc);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new char[n][m];
        chk = new int[n][m];

        for (int i = 0; i < n; i++) {
            char[] tmp2 = br.readLine().toCharArray();
            for (int j = 0; j < tmp2.length; j++) {
                area[i][j] = tmp2[j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] != '#' && chk[i][j] == 0) {
                    go(i, j);
                    if (o <= v) av += v;
                    else ao += o;
                    o = 0;
                    v = 0;
                }
            }
        }
        System.out.println(ao + " " + av);
    }
}
