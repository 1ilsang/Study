//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcJ2sapZMDFAV8

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int tcase = Integer.parseInt(st.nextToken());

        for (int t = 1; t <= tcase; t++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int list[] = new int[405];
            int ans = 1;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if(a > b) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                if(a % 2 == 0) list[a - 1]++;
                for (int j = a; j <= b; j++) list[j]++;
                for(int j = 0; j <= 400; j++ ) if (list[j] > ans) ans = list[j];
            }
            System.out.printf("#%d %d\n", t, ans);
        }
    }
}
