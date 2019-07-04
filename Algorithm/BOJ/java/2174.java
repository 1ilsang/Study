//https://www.acmicpc.net/problem/2174
//http://1ilsang.blog.me/221577455628

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int n, m;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area;
    private static Node[] robots = new Node[102];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        m = Integer.parseInt(str[0]) + 1;
        n = Integer.parseInt(str[1]) + 1;
        area = new int[n][m];
        str = br.readLine().split(" ");

        int a = Integer.parseInt(str[0]);
        int b = Integer.parseInt(str[1]);

        for (int i = 1; i <= a; i++) {
            str = br.readLine().split(" ");

            int c = Integer.parseInt(str[0]);
            int r = Integer.parseInt(str[1]);
            int d = 0;

            if (str[2].equals("N")) d = 3;
            else if (str[2].equals("E")) d = 0;
            else if (str[2].equals("S")) d = 1;
            else d = 2;

            robots[i] = new Node(n - r, c, d);
            area[n - r][c] = i;
        }
        boolean flag = false;
        for (int k = 0; k < b; k++) {
            str = br.readLine().split(" ");
            int targetNo = Integer.parseInt(str[0]);
            char cmd = str[1].charAt(0);
            int loop = Integer.parseInt(str[2]);
            Node nowRobot = robots[targetNo];

            for (int i = 0; i < loop; i++) {
                if (flag) continue;
                if (cmd == 'F') {
                    int nr = nowRobot.r + dr[nowRobot.d];
                    int nc = nowRobot.c + dc[nowRobot.d];
                    if (nr < 1 || nc < 1 || nr >= n || nc >= m) {
                        System.out.printf("Robot %d crashes into the wall\n", targetNo);
                        flag = true;
                        break;
                    } else if (area[nr][nc] > 0) {
                        System.out.printf("Robot %d crashes into robot %d\n", targetNo, area[nr][nc]);
                        flag = true;
                        break;
                    } else {
                        area[nowRobot.r][nowRobot.c] = 0;
                        area[nr][nc] = targetNo;
                        robots[targetNo].r = nr;
                        robots[targetNo].c = nc;
                    }
                } else if (cmd == 'L') {
                    if (--nowRobot.d < 0) nowRobot.d = 3;
                } else if (cmd == 'R') {
                    if (++nowRobot.d == 4) nowRobot.d = 0;
                }
            }
        }

        if (!flag) System.out.println("OK");
    }

    private static class Node {
        int r, c, d;

        public Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
}
