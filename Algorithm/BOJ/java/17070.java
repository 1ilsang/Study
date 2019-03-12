//https://www.acmicpc.net/problem/17070

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AD1_Bus {
    private static int n;
    private static int[][] area;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        area = new int[n + 1][n + 1];
        for (int i = 0; i < n; i++) {
            String[] tmp = br.readLine().split(" ");
            for (int j = 0; j < n; j++) area[i + 1][j + 1] = Integer.parseInt(tmp[j]);
        }
        System.out.println(dp());
    }

    private static long dp() {
        long[][][] dp = new long[n + 1][n + 1][3];
        dp[1][2][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (area[i][j] == 1) continue;
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
                if (area[i][j - 1] != 1 && area[i - 1][j] != 1) {
                    dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
                dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
            }
        }
        return dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    }
}
