//https://www.acmicpc.net/problem/11404
//https://1ilsang.blog.me/221563668868

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int INF = 200002;
        int n = Integer.parseInt(br.readLine()) + 1;
        int[][] dist = new int[n][n];
        int[][] ans = new int[n][n];
        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; i++) {
            String[] str = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            int c = Integer.parseInt(str[2]);
            if (dist[a][b] == 0 || dist[a][b] > c) dist[a][b] = c;
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++) {
                if (dist[i][j] == 0 && i != j) ans[i][j] = INF;
                else ans[i][j] = dist[i][j];
            }
        for (int k = 1; k < n; k++) {
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    if (ans[i][k] + ans[k][j] < ans[i][j]) ans[i][j] = ans[i][k] + ans[k][j];
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                System.out.print((ans[i][j] >= INF ? 0 : ans[i][j]) + " ");
            }
            System.out.println();
        }
    }
}
