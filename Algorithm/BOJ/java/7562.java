//https://www.acmicpc.net/problem/7562

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n;
    private static Node start, target;
    private static int[][] chk;
    private static int[] dr = {-2, -1, 1, 2, 2, 1, -1, -2};
    private static int[] dc = {1, 2, 2, 1, -1, -2, -2, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        while (tcase-- > 0) {
            n = Integer.parseInt(br.readLine());
            chk = new int[n][n];
            String[] tmp = br.readLine().split(" ");
            start = new Node(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]));
            tmp = br.readLine().split(" ");
            target = new Node(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]));
            System.out.println(go());
        }
    }

    private static int go() {
        int ret = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(start);
        chk[start.r][start.c] = 1;
        while (!queue.isEmpty()) {
            int r = queue.peek().r;
            int c = queue.peek().c;
            int p = queue.peek().p;
            queue.poll();
            if (r == target.r && c == target.c) {
                ret = p;
                break;
            }
            for(int i = 0; i < 8 ; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || chk[nr][nc] == 1) continue;
                chk[nr][nc] = 1;
                queue.offer(new Node(nr, nc, p + 1));
            }
        }
        return ret;
    }

    private static class Node {
        int r, c, p;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public Node(int r, int c, int p) {
            this(r, c);
            this.p = p;
        }
    }
}
