//https://www.acmicpc.net/problem/16956

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m;
    private static char[][] area;
    private static int[][] chk;
    private static int[] dr = {0, 1, 0, -1};
    private static int[] dc = {1, 0, -1, 0};
    private static Queue<Node> queue;

    private static int bfs() {
        boolean flag = false;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();

            for(int i = 0 ; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1) continue;
                if(area[nr][nc] == 'S') {
                    flag = true;
                    break;
                }
                chk[nr][nc] = 1;
                if(area[nr][nc] == '.') area[nr][nc] = 'D';
            }
            if(flag) break;
        }
        return flag ? 0 : 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new char[n][m];
        chk = new int[n][m];
        queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            char[] tmp2 = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                area[i][j] = tmp2[j];
                if (area[i][j] == 'W') queue.offer(new Node(i, j));
            }
        }
        int ret = bfs();
        System.out.println(ret);
        if(ret == 1) print();
    }

    private static void print() {
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                System.out.print(area[i][j]);
            }System.out.println();
        }
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
