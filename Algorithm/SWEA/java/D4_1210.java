//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh&categoryId=AV14ABYKADACFAYh&categoryType=CODE
//http://1ilsang.blog.me/221580857319

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    private static int[] dr = {0, 0, -1};
    private static int[] dc = {-1, 1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 1; t <= 10; t++) {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] area = new int[100][100];
            boolean[][] visit = new boolean[100][100];
            int r = 0, c = 0, ans = 0;

            for (int i = 0; i < 100; i++) {
                String[] str = br.readLine().split(" ");
                for (int j = 0; j < 100; j++) {
                    area[i][j] = Integer.parseInt(str[j]);
                    if (area[i][j] == 2) {
                        r = i;
                        c = j;
                    }
                }
            }

            while (true) {
                boolean flag = false;
                visit[r][c] = true;
                for (int i = 0; i < 3; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr == 0) {
                        ans = c;
                        flag = true;
                        break;
                    }
                    if (nr < 0 || nc < 0 || nc > 99 || area[nr][nc] == 0 ||  visit[nr][nc]) continue;
                    r = nr;
                    c = nc;
                    break;
                }
                if (flag) break;
            }
            System.out.printf("#%d %d\n", t, ans);
        }
    }
}
