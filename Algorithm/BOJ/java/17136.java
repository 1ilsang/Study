//https://www.acmicpc.net/problem/17136
//https://1ilsang.blog.me/221572320270

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static final int INF = 100000;
    private static int[] pages = {5, 5, 5, 5, 5};
    private static int[][] area = new int[10][10];
    private static boolean[][] visited = new boolean[10][10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int remains = 0;
        for (int i = 0; i < 10; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < 10; j++) {
                area[i][j] = Integer.parseInt(str[j]);
                if (area[i][j] == 1) remains++;
            }
        }
        int ret = go(0, 0, remains);
        System.out.println(ret == INF ? -1 : ret);
    }

    private static int go(int lo, int r, int remains) {
        int ret = INF;

        if (remains < 0) return INF;
        else if (remains == 0) return lo;

        for (int i = r; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (area[i][j] == 0 || visited[i][j]) continue;
                boolean able = true;
                for (int k = 0; k < 5; k++) {
                    if (pages[k] == 0) continue;
                    if (!isAbleSize(i, j, k + 1)) {
                        able = false;
                        break;
                    }
                    setVisited(i, j, k + 1, true);
                    pages[k]--;
                    int inRet = go(lo + 1, i, remains - (k + 1) * (k + 1));
                    ret = inRet < ret ? inRet : ret;
                    pages[k]++;
                    setVisited(i, j, k + 1, false);
                }
                if (!able) return ret;
            }
        }

        return ret;
    }

    private static boolean isAbleSize(int r, int c, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (r + i > 9 || c + j > 9 || area[r + i][c + j] == 0 || visited[r + i][c + j]) return false;
            }
        }
        return true;
    }

    private static void setVisited(int r, int c, int size, boolean flag) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                visited[r + i][c + j] = flag;
            }
        }
    }
}
