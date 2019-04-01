//https://www.acmicpc.net/problem/11950

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int n, m, ans;
    private static int[][] color;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        color = new int[n][3];
        ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                if (line[j] == 'W') color[i][0]++;
                else if (line[j] == 'B') color[i][1]++;
                else if (line[j] == 'R') color[i][2]++;
            }
        }
        backtracking(1, 0, color[0][1] + color[0][2], 1);
        System.out.println(ans);
    }

    private static void backtracking(int r, int nowColor, int totalValue, int count) {
        if (r == n) {
            if (count < 3) return;
            if (ans > totalValue) ans = totalValue;
            return;
        }
        for (int i = nowColor; i < 3; i++) {
            int nextValue = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                nextValue += color[r][j];
            }
            backtracking(r + 1, i, totalValue + nextValue, nowColor != i ? count + 1 : count);
        }
    }
}
