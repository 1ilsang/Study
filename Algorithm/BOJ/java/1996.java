//https://www.acmicpc.net/problem/1996

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private final static int[] dr = {0, 1, 0, -1, -1, 1, 1, -1};
    private final static int[] dc = {1, 0, -1, 0, 1, 1, -1, -1};
    private static int[][] area;
    private static char[][] chk;
    private static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        area = new int[n][n];
        chk = new char[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for (int j = 0; j < n; j++) area[i][j] = line.charAt(j) - '0';
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(area[i][j] > 0) chk[i][j] = '*';
                else {
                    int hit = 0;
                    for(int d = 0 ; d < 8; d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];
                        if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                        if(area[nr][nc] > 0) hit += area[nr][nc];
                    }
                    String tmp = hit + "";
                    if(hit > 9) tmp = "M";
                    chk[i][j] = tmp.charAt(0);
                }
                System.out.print(chk[i][j]);
            }System.out.println();
        }
    }
}
