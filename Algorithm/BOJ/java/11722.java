//https://www.acmicpc.net/problem/11722
//http://1ilsang.blog.me/221496245689

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] list = new int[n];
        int[] dp = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) list[i] = sc.nextInt();
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            int nowMaxN = list[i];
            for (int j = i + 1; j < n; j++) {
                if (nowMaxN > list[j]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            if (dp[i] > ans) ans = dp[i];
        }
        System.out.println(ans);
    }
}
