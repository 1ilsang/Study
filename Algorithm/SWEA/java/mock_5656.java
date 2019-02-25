//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static int n, w, h;
    private static int[][] area, tmpArea;
    private static LinkedList<Integer> list;

    private static int go() {
        int ret = Integer.MAX_VALUE;

        if (list.size() == n) {
            tmpArea = new int[h][w];
            for(int i = 0; i < h; i++) {
                for(int j = 0 ; j < w; j++) {
                    tmpArea[i][j] = area[i][j];
                }
            }

            for (int i = 0; i < list.size(); i++) {
                int cur = list.get(i);
                if (hit(cur)) {
                    for(int j = 0 ; j < w; j++) down(j);
                }
            }
            return getBoxes();
        }

        for (int i = 0; i < w; i++) {
            list.add(i);
            ret = Math.min(ret, go());
            list.pollLast();
        }

        return ret;
    }

    private static boolean hit(int col) {
        boolean flag = false;
        for (int i = 0; i < h; i++) {
            if (tmpArea[i][col] > 0) {
                flag = true;
                explosion(i, col);
                break;
            }
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

    private static void explosion(int sr, int sc) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(sr, sc));
        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int n = tmpArea[r][c];
            tmpArea[r][c] = 0;
            queue.poll();

            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < n; j++) {
                    int nr = r + dr[i] * j;
                    int nc = c + dc[i] * j;
                    if (nr < 0 || nc < 0 || nr >= h || nc >= w || tmpArea[nr][nc] == 0) continue;
                    queue.offer(new Node(nr, nc));
                }
            }
        }
    }

    private static void down(int col) {
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < h; i++) if (tmpArea[i][col] > 0) list.add(tmpArea[i][col]);
        for (int i = 0; i < h - list.size(); i++) tmpArea[i][col] = 0;
        for (int i = h - list.size(); i < h; i++) tmpArea[i][col] = list.pollFirst();
    }

    private static int getBoxes() {
        int ret = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (tmpArea[i][j] > 0) ret++;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String[] tmp = br.readLine().split(" ");
            n = Integer.parseInt(tmp[0]);
            w = Integer.parseInt(tmp[1]);
            h = Integer.parseInt(tmp[2]);
            area = new int[h][w];
            list = new LinkedList<>();

            for (int i = 0; i < h; i++) {
                tmp = br.readLine().split(" ");
                for (int j = 0; j < w; j++) {
                    area[i][j] = Integer.parseInt(tmp[j]);
                }
            }

            System.out.printf("#%d %d\n", t, go());
        }
    }
}
