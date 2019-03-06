//https://www.acmicpc.net/problem/1976

import java.util.*;

public class Main {
    private static int[] parents;

    private static int find(int n) {
        if (parents[n] == -1) return n;
        return parents[n] = find(parents[n]);
    }

    private static void union(int a, int b) {
        int ar = find(a);
        int br = find(b);
        if (ar == br) return;
        parents[br] = ar;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int area[][] = new int[n][n];
        int[] list = new int[m];
        parents = new int[n];
        for (int i = 0; i < n; i++) parents[i] = -1;

        boolean flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.nextInt();
                if (area[i][j] > 0) union(i, j);
            }
        }
        for (int i = 0; i < m; i++) list[i] = sc.nextInt() - 1;
        for (int i = 1; i < m; i++) if (find(list[i - 1]) != find(list[i])) flag = false;
        System.out.println(flag ? "YES" : "NO");
    }
}
