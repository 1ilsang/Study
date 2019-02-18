//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int n;
    private static int[] chkR, chkC, chkLD, chkRD;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tcase; t++) {
            n = Integer.parseInt(br.readLine());
            chkR = new int[n];
            chkC = new int[n];
            chkLD = new int[n * 2];
            chkRD = new int[n * 2];

            System.out.println("#" + t + " " + backTracking(0, 0, 0));
        }
    }

    private static int backTracking(int r, int c, int lo) {
        int ret = 0;
        if(lo == n) return 1;
        for (int i = r; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(chk(i, j)) {
                    toggleChk(i, j, 1);
                    ret += backTracking(i, j, lo + 1);
                    toggleChk(i, j, 0);
                }
            }
        }
        return ret;
    }
    private static boolean chk(int r, int c) {
        return (chkR[r] == 0 && chkC[c] == 0 && chkLD[r - c + n - 1] == 0 && chkRD[r + c] == 0);
    }
    private static void toggleChk(int r, int c, int toggle) {
        chkR[r] = toggle;
        chkC[c] = toggle;
        chkLD[r - c + n - 1] = toggle;
        chkRD[r + c] = toggle;
    }
}
