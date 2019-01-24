//https://www.acmicpc.net/problem/14500

import java.io.*;

public class Main {
    private static int n, m;
    private static int[][] area;

    private static int[][][] tetromino = {
            // ㅡ
            {{0,0,0,0}, {0,1,2,3}},
            {{0,1,2,3}, {0,0,0,0}},
            {{0,0,0,0}, {0,1,2,3}},
            {{0,1,2,3}, {0,0,0,0}},
            // ㅁ
            {{0,0,1,1}, {0,1,0,1}},
            {{0,0,1,1}, {0,1,0,1}},
            {{0,0,1,1}, {0,1,0,1}},
            {{0,0,1,1}, {0,1,0,1}},
            // L
            {{0,1,2,2}, {0,0,0,1}},
            {{0,0,0,1}, {0,1,2,0}},
            {{0,0,1,2}, {0,1,1,1}},
            {{1,1,1,0}, {0,1,2,2}},
            // rL
            {{0,1,2,2}, {1,1,1,0}},
            {{0,1,1,1}, {0,0,1,2}},
            {{0,1,2,0}, {0,0,0,1}},
            {{0,0,0,1}, {0,1,2,2}},
            // rㄹ
            {{0,1,1,2}, {0,0,1,1}},
            {{1,1,0,0}, {0,1,1,2}},
            {{0,1,1,2}, {0,0,1,1}},
            {{1,1,0,0}, {0,1,1,2}},
            // ㄹ
            {{0,1,1,2}, {1,1,0,0}},
            {{0,0,1,1}, {0,1,1,2}},
            {{0,1,1,2}, {1,1,0,0}},
            {{0,0,1,1}, {0,1,1,2}},
            // ㅗ
            {{0,0,0,1}, {0,1,2,1}},
            {{0,1,1,2}, {1,0,1,1}},
            {{0,1,1,1}, {1,0,1,2}},
            {{0,1,2,1}, {0,0,0,1}}
    };

    private static int go(int r, int c) {
        int ret = 0;
        for (int j = 0; j < 28; j++) {
            int tmp = 0;
            for (int i = 0; i < 4; i++) {
                int nr = r + tetromino[j][0][i];
                int nc = c + tetromino[j][1][i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    tmp += area[nr][nc];
                } else {
                    tmp = 0;
                    break;
                }
            }
            ret = Math.max(tmp, ret);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int ans = 0;
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new int[n][m];

        for (int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans = Math.max(ans, go(i, j));
        System.out.println(ans);
//        bw.write(ans);

        br.close();
        bw.close();
    }
}
