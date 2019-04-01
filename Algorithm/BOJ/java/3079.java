//https://www.acmicpc.net/problem/3079

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] list = new int[n];
            long maxN = 0;
            for (int i = 0; i < n; i++) {
                list[i] = sc.nextInt();
                if(list[i] > maxN) maxN = list[i];
            }
            long r = maxN * m;
            long l = 0;
            long ans = 0;

            while (l <= r) {
                long mid = (r + l) >> 1;
                long cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += mid / list[i];
                }
                if(cnt < m) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                    ans = mid;
                }
            }
            System.out.println(ans);
    }
}
