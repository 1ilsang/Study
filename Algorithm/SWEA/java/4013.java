//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    private static int[][] area;
    private static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine().trim());
        for (int t = 1; t <= tcase; t++) {
            int ans = 0;
            int k = Integer.parseInt(br.readLine().trim());
            area = new int[4][8];
            for (int i = 0; i < 4; i++) {
                String[] tmp = br.readLine().split(" ");
                for (int j = 0; j < 8; j++) area[i][j] = Integer.parseInt(tmp[j]);
            }
            for (int i = 0; i < k; i++) {
                String[] tmp = br.readLine().split(" ");
                int n = Integer.parseInt(tmp[0]);
                int d = Integer.parseInt(tmp[1]);
                chk = new boolean[4];
                go(n - 1, d == 1);
            }
            for (int i = 1; i <= 4; i++) if (area[i - 1][0] == 1) ans += 1 << i;
            System.out.printf("#%d %d\n", t, ans >> 1);
        }
    }

    private static void go(int n, boolean d) {
        chk[n] = true;
        int[] tmp = new int[8];
        int sidx = d ? 1 : -1;
        int midx = d ? 0 : 6;
        tmp[midx] = area[n][7];
        tmp[midx + 1] = area[n][0];
        for (int i = 1; i < 7; i++) tmp[++sidx] = area[n][i];
        if (n - 1 >= 0 && !chk[n - 1] && area[n - 1][2] != area[n][6]) go(n - 1, !d);
        if (n + 1 < 4 && !chk[n + 1] && area[n][2] != area[n + 1][6]) go(n + 1, !d);
        for (int i = 0; i < 8; i++) area[n][i] = tmp[i];
    }
}
