//https://www.acmicpc.net/problem/2234
//https://1ilsang.blog.me/221579787484

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Main {
    private static int[] dr = {1, 0, -1, 0};
    private static int[] dc = {0, 1, 0, -1};
    private static Node[][] nArea;
    private static int[][] area;
    private static boolean[][] visit;
    private static int m, n, roomCnt, roomMaxValue;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        m = Integer.parseInt(str[0]);
        n = Integer.parseInt(str[1]);
        area = new int[n][m];
        nArea = new Node[n][m];
        visit = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(str[j]);
            }
        }

        setNodeArea();
        getRoomValues();

        System.out.printf("%d\n%d\n%d\n", roomCnt, roomMaxValue, goBreak());
    }

    private static void setNodeArea() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nArea[i][j] = new Node(getWallState(area[i][j]), 0, i, j, -1);
            }
        }
    }

    private static boolean[] getWallState(int value) {
        boolean[] ret = new boolean[4];
        int cnt = 0;
        for (int i = 8; i > 0; i /= 2) {
            if (value - i >= 0) {
                value -= i;
                ret[cnt] = true;
            }
            cnt++;
        }
        return ret;
    }

    private static void getRoomValues() {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j]) continue;
                int ret = getRoomSize(i, j, roomCnt++);
                roomMaxValue = ret > roomMaxValue ? ret : roomMaxValue;
            }
        }
    }

    private static int getRoomSize(int i, int j, int roomNumber) {
        Queue<Node> queue = new LinkedList<>();
        Queue<Node> totalSetList = new LinkedList<>();
        int ret = 0;
        visit[i][j] = true;
        queue.offer(nArea[i][j]);
        totalSetList.offer(nArea[i][j]);

        while (!queue.isEmpty()) {
            ret++;
            int r = queue.peek().r;
            int c = queue.peek().c;
            boolean[] wall = queue.peek().walls;
            queue.poll();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc] || wall[d]) continue;
                visit[nr][nc] = true;
                queue.offer(nArea[nr][nc]);
                totalSetList.offer(nArea[nr][nc]);
            }
        }

        for (Node e : totalSetList) {
            nArea[e.r][e.c].total = ret;
            nArea[e.r][e.c].no = roomNumber;
        }

        return ret;
    }

    private static int goBreak() {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || nArea[nr][nc].no == nArea[i][j].no)
                        continue;

                    int bTotal = nArea[nr][nc].total + nArea[i][j].total;
                    if (bTotal > ret) {
                        ret = bTotal;
                    }
                }
            }
        }
        return ret;
    }

    private static class Node {
        boolean[] walls;
        int total, r, c, no;

        public Node(boolean[] walls, int total, int r, int c, int no) {
            this.walls = walls;
            this.total = total;
            this.r = r;
            this.c = c;
            this.no = no;
        }
    }
}
