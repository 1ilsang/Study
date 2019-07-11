//https://www.acmicpc.net/problem/1799
//https://1ilsang.blog.me/221583343986

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    private static int n, ans;
    private static int[][] area;
    private static boolean[][] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        area = new int[n][n];
        chk = new boolean[n * 2 + 1][2];

        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < n; j++) area[i][j] = Integer.parseInt(str[j]);
        }
        int ret = 0;
        go(0, 0, 0, true);
        ret += ans;
        ans = 0;
        go(0, 1, 0, false);
        System.out.println(ret + ans);
    }

    private static void go(int r, int c, int cnt, boolean white) {
        if (ans < cnt) ans = cnt;
        if (c >= n - 1) {
            r = r + 1;
        }
        for (int i = r; i < n; i++) {
            for (int j = white ? (i % 2 == 0 ? 0 : 1) : (i % 2 == 0 ? 1 : 0); j < n; j += 2) {
                if (area[i][j] == 0 || chk[i + j][0] || chk[i - j + n][1]) continue;
                chk[i + j][0] = true;
                chk[i - j + n][1] = true;
                go(i, j, cnt + 1, white);
                chk[i + j][0] = false;
                chk[i - j + n][1] = false;
            }
        }
    }
}
