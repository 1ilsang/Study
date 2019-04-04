//https://www.acmicpc.net/problem/3055

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private static int[] dr = {0,1,0,-1};
    private static int[] dc = {1,0,-1,0};
    private static int[][] area, chk;
    private static Queue<Node> queue;
    private static int n, m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new int[n][m];
        chk = new int[n][m];
        queue = new LinkedList<>();
        Node start = null;
        for(int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for(int j = 0 ; j < m; j++) {
                area[i][j] = line[j];
                if(area[i][j] == '*') {
                    queue.offer(new Node(i, j, -1));
                    chk[i][j] = 1;
                }
                else if(area[i][j] == 'S') {
                    start = new Node(i, j, 0);
                    chk[i][j] = 1;
                }
            }
        }
        queue.offer(start);
        int ret = bfs();
        System.out.println(ret == -1 ? "KAKTUS" : ret);
    }
    private static int bfs() {
        int ret = -1;
        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            queue.poll();

            if(area[r][c] == 'D' && p != -1) {
                ret = p;
                break;
            }

            for(int i = 0 ; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || area[nr][nc] == 'X' || chk[nr][nc] == 1) continue;
                if(p != -1) {
                    chk[nr][nc] = 1;
                    queue.offer(new Node(nr, nc, p + 1));
                }
                else if(area[nr][nc] != 'D') {
                    queue.offer(new Node(nr, nc, -1));
                    chk[nr][nc] = 1;
                }
            }
        }
        return ret;
    }
    private static class Node {
        int r, c, p;

        public Node(int r, int c, int p) {
            this.r = r;
            this.c = c;
            this.p = p;
        }
    }
}
