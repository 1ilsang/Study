//https://www.acmicpc.net/problem/14891

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int[][] area;
    private static int[] chk;

    public static void main(String[] args) throws IOException {
        int ans = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        area = new int[5][8];
        for (int i = 0; i < 4; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < 8; j++) area[i + 1][j] = tmp[j] - '0';
        }
        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            chk = new int[5];
            String[] cmd = br.readLine().split(" ");
            int n = Integer.parseInt(cmd[0]);
            int d = Integer.parseInt(cmd[1]);
            boolean flag = false;
            if (d == 1) flag = true;
            go(n, flag);
        }
        for (int i = 1; i < 5; i++) if (area[i][0] == 1) ans += Math.pow(2, i - 1);
        System.out.println(ans);
    }

    private static void go(int n, boolean d) {
        int[][] tmp = new int[5][8];
        chk[n] = 1;
        for (int j = 0; j < 8; j++) tmp[n][j] = area[n][j];
        int start;
        if (!d) {
            start = tmp[n][0];
            for (int i = 0; i < 7; i++) tmp[n][i] = tmp[n][i + 1];
            tmp[n][7] = start;
        } else {
            start = tmp[n][7];
            for (int i = 7; i > 0; i--) tmp[n][i] = tmp[n][i - 1];
            tmp[n][0] = start;
        }
        if (n - 1 > 0 && chk[n - 1] == 0) if (area[n][6] != area[n - 1][2]) go(n - 1, !d);
        if (n + 1 < 5 && chk[n + 1] == 0) if (area[n][2] != area[n + 1][6]) go(n + 1, !d);

        for (int j = 0; j < 8; j++) area[n][j] = tmp[n][j];
    }
}
