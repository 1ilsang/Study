//https://www.acmicpc.net/problem/9205
//http://1ilsang.blog.me/221471480791

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static class Node {
        int x, y;

        private Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int n = Integer.parseInt(br.readLine());
            boolean flag = false;
            int[][] dist = new int[n + 2][n + 2];
            int[] chk = new int[n + 2];
            Node[] nodes = new Node[n + 2];
            for (int i = 0; i < n + 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                nodes[i] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    dist[i][j] = Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y);
                }
            }

            Queue<Integer> queue = new LinkedList<>();
            queue.offer(0);
            chk[0] = 1;
            while (!queue.isEmpty()) {
                int now = queue.poll();
                if (now == n + 1) {
                    flag = true;
                    break;
                }
                for (int i = 0; i < n + 2; i++) {
                    if (chk[i] == 0 && now != i && dist[now][i] <= 1000) {
                        chk[i] = 1;
                        queue.offer(i);
                    }
                }
            }
            String ans = flag ? "happy" : "sad";
            System.out.println(ans);
        }
    }
}
