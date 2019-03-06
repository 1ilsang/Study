//https://www.acmicpc.net/problem/14647

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static int[][] area;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) area[i][j] = Integer.parseInt(st.nextToken());
        }

        int maxCnt = 0;
        int maxLine = 0;
        for (int i = 0; i < n; i++) {
            int line9 = 0;
            for (int j = 0; j < m; j++) line9 += get9(area[i][j]);
            maxCnt += line9;
            if(maxLine < line9) maxLine = line9;
        }
        for(int i = 0 ; i < m; i++) {
            int line9 = 0;
            for(int j = 0 ; j < n; j++) line9 += get9(area[j][i]);
            if(maxLine < line9) maxLine = line9;
        }
        System.out.println(maxCnt - maxLine);
    }

    private static int get9(int n) {
        int ret = 0;
        while (n > 0) {
            if (n % 10 == 9) ret++;
            n /= 10;
        }
        return ret;
    }
}
