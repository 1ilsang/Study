//https://www.acmicpc.net/problem/2960

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println(era(n, m));
    }

    private static int era(int n, int k) {
        int cnt = 0;
        boolean[] arr = new boolean[n+1];
        arr[0] = arr[1] = true;
        for(int i = 2; i <= n; i++) {
            if(arr[i]) continue;
            cnt++;
            if(cnt == k) return i;
            for(int j = i + i; j <= n; j+=i) {
                if(arr[j]) continue;
                arr[j] = true;
                cnt++;
                if(cnt == k) return j;
            }
        }
        return 0;
    }
}
