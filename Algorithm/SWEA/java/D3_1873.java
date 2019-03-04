//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LyE7KD2ADFAXc

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    private enum TankDirection {
        R, D, L, U, S
    }

    private static int n, m;
    private static char[][] area;
    private static Node tank;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static char[] tankDirection = {'>', 'v', '<', '^'};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String[] tmp = br.readLine().split(" ");
            n = Integer.parseInt(tmp[0]);
            m = Integer.parseInt(tmp[1]);
            area = new char[n][m];
            for (int i = 0; i < n; i++) {
                char[] line = br.readLine().toCharArray();
                for (int j = 0; j < m; j++) {
                    area[i][j] = line[j];
                    if (area[i][j] == '<' || area[i][j] == '>' || area[i][j] == '^' || area[i][j] == 'v') {
                        tank = new Node(i, j, area[i][j]);
                    }
                }
            }
            int cmdLength = Integer.parseInt(br.readLine());
            String cmd = br.readLine();
            for (int i = 0; i < cmdLength; i++) go(cmd.charAt(i));
            print(t);
        }
    }

    private static void go(char cmd) {
        int r = tank.r;
        int c = tank.c;
        TankDirection getEnum = TankDirection.valueOf(cmd + "");
        int d = getEnum.ordinal();
        if (d != 4) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (isMoving(nr, nc, 0)) {
                area[r][c] = '.';
                area[nr][nc] = tankDirection[d];
                tank.r = nr;
                tank.c = nc;
            } else area[r][c] = tankDirection[d];
            tank.setDirection(area[tank.r][tank.c]);
        } else fire(tank.d, r, c);
    }

    private static void fire(int d, int r, int c) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        while (isMoving(nr, nc, 1)) {
            if (area[nr][nc] == '*') {
                area[nr][nc] = '.';
                break;
            } else if (area[nr][nc] == '#') break;
            nr += dr[d];
            nc += dc[d];
        }
    }


    private static boolean isMoving(int r, int c, int type) {
        if (type == 0) if (r < 0 || c < 0 || r >= n || c >= m || area[r][c] != '.') return false;
        if (type == 1) if (r < 0 || c < 0 || r >= n || c >= m) return false;
        return true;
    }

    private static void print(int t) {
        System.out.printf("#%d ", t);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(area[i][j]);
            }
            System.out.println();
        }
    }

    private static class Node {
        int r, c, d;

        public Node(int r, int c, char direction) {
            this.r = r;
            this.c = c;
            setDirection(direction);
        }

        private void setDirection(char direction) {
            if (direction == '>') d = 0;
            else if (direction == 'v') d = 1;
            else if (direction == '<') d = 2;
            else if (direction == '^') d = 3;
        }
    }
}
