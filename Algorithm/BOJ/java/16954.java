//https://www.acmicpc.net/problem/16954

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static char[][][] area;
    private static int[][][] chk;
    private static int[] dr = {0,1,0,-1,-1,1,1,-1};
    private static int[] dc = {1,0,-1,0,1,1,-1,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        area = new char[8][8][10];
        chk = new int[8][8][10];

        for (int i = 0; i < 8; i++) {
            st = new StringTokenizer(br.readLine());
            char[] line = st.nextToken().toCharArray();
            for (int j = 0; j < 8; j++) area[i][j][0] = line[j];
        }
        for(int i = 1 ; i <= 8 ; i++) wallsDown(i);
        System.out.println(bfs());
    }

    private static int bfs() {
        int ret = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(7, 0, 0));
        chk[7][0][0] = 1;

        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            queue.poll();
            int tp = p > 8 ? 8 : p;

            if (r == 0 && c == 7) {
                ret = 1;
                break;
            }

            if (p < 8 && chk[r][c][p + 1] == 0 && area[r][c][p + 1] != '#') {
                chk[r][c][p + 1] = 1;
                queue.offer(new Node(r, c, p + 1));
            }
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8 || area[nr][nc][tp] == '#' || chk[nr][nc][tp] == 1) continue;
                if(p  <= 8 && (area[nr][nc][tp + 1] == '#' || chk[nr][nc][tp + 1] == 1)) continue;
                chk[nr][nc][tp + 1] = 1;
                queue.offer(new Node(nr, nc, tp + 1));
            }
        }
        return ret;
    }

    private static void wallsDown(int p) {
        for(int i = 0; i < 8; i++) {
            LinkedList<Character> list = new LinkedList<>();
            list.add('.');
            for(int j = 0 ; j < 7; j++) list.add(area[j][i][p-1]);
            for(int j = 0; j < 8; j++) area[j][i][p] = list.pollFirst();
        }
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
