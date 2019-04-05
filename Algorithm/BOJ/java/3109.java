//https://www.acmicpc.net/problem/3109
//http://1ilsang.blog.me/221506048119

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int n, m, ans;
    private static int[] dr = {-1, 0, 1};
    private static int[] dc = {1, 1, 1};
    private static char[][] area;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new char[n][m];
        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) area[i][j] = line[j];
        }
        for (int i = 0; i < n; i++) if(dfs(i, 0)) ans++;
        System.out.println(ans);
    }

    private static boolean dfs(int r, int c) {
        area[r][c] = 'x';
        if(c == m - 1) return true;
        for(int i = 0 ; i < 3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || area[nr][nc] == 'x') continue;
            if(dfs(nr, nc)) return true;
        }
        return false;
    }
}
