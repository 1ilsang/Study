//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-hF8KdBADFAVT

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int tcase = Integer.parseInt(st.nextToken());
        final int SIZE = 1000001;
        long[] dp = new long[SIZE];

        for (int i = 1; i < SIZE; i += 2) for (int j = 1; j * i < SIZE; j++) dp[j * i] += i;
        for (int i = 1; i < SIZE - 1; i++) dp[i + 1] += dp[i];

        for (int t = 1; t <= tcase; t++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            System.out.printf("#%d %d\n", t, dp[m] - dp[n - 1]);
        }
    }
}
