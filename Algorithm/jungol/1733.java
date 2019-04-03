//http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1006&sca=2040
//http://1ilsang.blog.me/221504305725

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class Main {
    private final static int N = 19;
    private final static int[] dr = {-1, 0, 1, 1,1,0,-1,-1};
    private final static int[] dc = {1, 1, 1, 0, -1,-1,-1,0};
    private static int[][] area;
    private static int[][][] chk;
    private static LinkedList<Node> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        area = new int[N][N];
        chk = new int[N][N][8];
        for (int i = 0; i < N; i++) {
            String[] tmp = br.readLine().split(" ");
            for (int j = 0; j < N; j++) area[i][j] = Integer.parseInt(tmp[j]);
        }
        boolean flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (area[i][j] != 0) {
                    for (int d = 0; d < 8; d++) {
                        chk[i][j][d] = 1;
                        int nr = i + dr[d];
                        int nc = j + dc[d];
                        if (nr < 0 || nc < 0 || nr >= N || nc >= N || chk[nr][nc][d] == 1 || area[nr][nc] != area[i][j]) continue;
                        list = new LinkedList<>();
                        list.add(new Node(i, j));
                        if (backtracking(nr, nc, d, area[nr][nc]) == 4) {
                            Collections.sort(list);
                            System.out.println(area[i][j]);
                            System.out.println((list.get(0).r + 1) + " " + (list.get(0).c + 1));
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) System.out.println(0);
    }

    private static int backtracking(int r, int c, int d, int nowColor) {
        list.add(new Node(r, c));
        chk[r][c][d] = 1;
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N || area[nr][nc] != nowColor) return 1;
        return backtracking(nr, nc, d, nowColor) + 1;
    }
    private static class Node implements Comparable<Node> {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public int compareTo(Node o) {
            if(this.c == o.c) return this.r - o.r;
            return this.c - o.c;
        }
    }
}
