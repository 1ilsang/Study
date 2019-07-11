//https://www.acmicpc.net/problem/9663

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    private static int n;
    private static boolean[][] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        chk = new boolean[n * 2 + 1][4];

        System.out.println(go(0, 0, 0));
    }

    private static int go(int r, int c, int cnt) {
        if (cnt == n) return 1;
        if (r == n) return 0;
        int ret = 0;

        for (int j = 0; j < n; j++) {
            if (chk[r][0] || chk[j][1] || chk[r - j + n][2] || chk[r + j][3]) continue;
            chk[r][0] = true;
            chk[j][1] = true;
            chk[r - j + n][2] = true;
            chk[r + j][3] = true;
            ret += go(r + 1, c + 1, cnt + 1);
            chk[r][0] = false;
            chk[j][1] = false;
            chk[r - j + n][2] = false;
            chk[r + j][3] = false;
        }

        return ret;
    }
}
