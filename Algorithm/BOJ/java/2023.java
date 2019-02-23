//https://www.acmicpc.net/problem/2023

import java.util.Scanner;

public class Main {

    private static boolean chkPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    private static void dfs(int cur, int n) {
        if (n == 0) {
            System.out.println(cur);
            return;
        }
        for (int i = 1; i < 10; i += 2) {
            int tmp = cur * 10 + i;
            if (chkPrime(tmp)) dfs(tmp, n - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] prime = {2, 3, 5, 7};
        for (int i = 0; i < 4; i++) dfs(prime[i], n - 1);
    }
}
