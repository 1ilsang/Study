//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGKdbqczEDFAUo
//https://blog.naver.com/1ilsang/221461026692

import java.io.*;

public class Solution {
    private static final int MOD = 1234567891;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int r = Integer.parseInt(line[1]);
            long fac[] = new long[n + 1];
            fac[0] = 1;
            for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;

            long bottom = (fac[r] * fac[n - r]) % MOD;
            long reBottom = fermat(bottom, MOD - 2);

            System.out.println((fac[n] * reBottom) % MOD);
        }
    }

    private static long fermat(long n, int x) {
        if (x == 0) return 1;
        long tmp = fermat(n, x / 2);
        long ret = (tmp * tmp) % MOD;
        if (x % 2 == 0) return ret;
        else return (ret * n) % MOD;
    }
}
