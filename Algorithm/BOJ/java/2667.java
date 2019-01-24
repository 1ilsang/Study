//https://www.acmicpc.net/problem/2667

import java.io.*;
import java.util.*;

public class Main {
    private static int n;
    private static int[][] area, chk;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};

    private static int dfs(int r, int c) {
        int ret = 1;
        chk[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && area[nr][nc] == 1 && chk[nr][nc] == 0) {
                ret += dfs(nr, nc);
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        ArrayList<Integer> list = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        area = new int[n][n];
        chk = new int[n][n];

        for (int i = 0; i < n; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                area[i][j] = tmp[j] - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] == 1 && chk[i][j] == 0) {
                    list.add(dfs(i, j));
                }
            }
        }

        Collections.sort(list);
        System.out.println(list.size());
        for (int i = 0; i < list.size(); i++) System.out.println(list.get(i));
    }
}
