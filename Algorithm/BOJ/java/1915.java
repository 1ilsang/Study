//https://www.acmicpc.net/problem/1915
//http://1ilsang.blog.me/221459856997

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int n, m;
    public static int[][] area, dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int ans = 0;

        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);
        area = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                area[i][j] = line[j] - '0';
                if(area[i][j] == 1) {
                    dp[i][j] = 1;
                    ans = 1;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (area[i][j] == 1) {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans = Math.max(dp[i][j], ans);
                }
            }
        }

        System.out.println(ans * ans);
    }
}
