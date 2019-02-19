//https://www.acmicpc.net/problem/14430

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        int[][] area = new int[n + 1][m + 1];
        int[][] chk = new int[n + 1][m + 1];

        for (int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i + 1][j + 1] = Integer.parseInt(tmp[j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                chk[i][j] = ((chk[i][j - 1] > chk[i - 1][j] ? chk[i][j - 1] : chk[i - 1][j]) + area[i][j]);
            }
        }
        System.out.println(chk[n][m]);
    }
}
