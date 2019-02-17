//https://www.acmicpc.net/problem/14502

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    private final static int dr[] = {0, 1, 0, -1};
    private final static int dc[] = {1, 0, -1, 0};
    private static int n, m, maxCnt;
    private static int[][] area;
    private static LinkedList<Node> list;

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        area = new int[n][m];
        list = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                area[i][j] = Integer.parseInt(tmp[j]);
                if (area[i][j] == 2) list.add(new Node(i, j));
                else if(area[i][j] == 0) maxCnt++;
            }
        }
        maxCnt -= 3;
        System.out.println(dfs(0,0,0));
    }
    private static int dfs(int sr, int sc, int lo) {
        int ret = 0;
        if(lo == 3) return bfs();
        for(int r = sr; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(area[r][c] == 0) {
                    area[r][c] = 1;
                    ret = Math.max(ret, dfs(r, c, lo + 1));
                    area[r][c] = 0;
                }
            }
        }
        return ret;
    }
    private static int bfs() {
        int ret = maxCnt;
        int[][] chk = new int[n][m];
        Queue<Node> queue = new LinkedList<>();
        for(int i = 0 ; i < list.size(); i++) {
            queue.offer(list.get(i));
            chk[list.get(i).r][list.get(i).c] = 1;
        }

        while(!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            queue.poll();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || chk[nr][nc] == 1 || area[nr][nc] != 0) continue;
                chk[nr][nc] = 1;
                queue.offer(new Node(nr, nc));
                ret--;
            }
        }
        return ret;
    }
}
