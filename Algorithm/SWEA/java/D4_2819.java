//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    private static HashSet<String> hashSet;
    private static char[][] area;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};

    private static int backTracking(int r, int c, String cur) {
        int ret = 0;
        if(cur.length() == 7) {
            if(!hashSet.contains(cur)) {
                hashSet.add(cur);
                return 1;
            } else return 0;
        }
        for(int i = 0 ; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr > 3 || nc > 3) continue;
            String tmp = cur + area[nr][nc];
            ret += backTracking(nr, nc, tmp);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tcase; t++) {
            int ans = 0;
            area = new char[4][4];
            hashSet = new HashSet<>();
            for (int i = 0; i < 4; i++) {
                String[] str = br.readLine().split(" ");
                for (int j = 0; j < 4; j++) {
                    area[i][j] = str[j].charAt(0);
                }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    ans += backTracking(i, j, area[i][j] + "");
                }
            }
            System.out.printf("#%d %d\n", t, ans);
        }
    }
}
