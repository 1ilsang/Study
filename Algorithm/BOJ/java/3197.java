//https://www.acmicpc.net/problem/3197
//https://1ilsang.blog.me/221582427670

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Main {
    private static int n, m;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int[][] area, copy;
    private static boolean[][] visit;
    private static Node duck;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        area = new int[n][m];
        copy = new int[n][m];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                area[i][j] = line.charAt(j);
                if (area[i][j] == 'L') duck = new Node(i, j);
            }
        }

        System.out.println(go());
    }

    private static int go() {
        int right = 0;
        int left = 0;
        int day = (right + left) >> 1;

        Queue<Node> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 'X') continue;
                queue.offer(new Node(i, j));
                copy[i][j] = 1;
            }
        }
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || copy[nr][nc] != 0) continue;
                copy[nr][nc] = copy[r][c] + 1;
                if (right < copy[nr][nc]) right = copy[nr][nc];
                queue.offer(new Node(nr, nc));
            }
        }

        day = (right + left) >> 1;
        while (left <= right) {
            visit = new boolean[n][m];
            if (isConnect(day)) right = day - 1;
            else left = day + 1;
            day = (left + right) >> 1;
        }

        return day;
    }

    private static boolean isConnect(int day) {
        Queue<Node> queue = new LinkedList<>();
        boolean flag = false;
        queue.offer(duck);
        visit[duck.r][duck.c] = true;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc] || copy[nr][nc] > day) continue;
                if (area[nr][nc] == 'L' && nr != duck.r && nc != duck.c) {
                    flag = true;
                    break;
                }
                visit[nr][nc] = true;
                queue.offer(new Node(nr, nc));
            }
            if (flag) break;
        }

        return flag;
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
