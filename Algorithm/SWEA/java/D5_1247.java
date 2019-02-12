//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution {
    private static class Node {
        int x, y;

        private Node() {}
    }

    private static Node[] nodes;
    private static int n, ans;
    private static int[][] dist;
    private static LinkedList<Integer> permutations;
    private static int[] chk;

    private static void go() {
        if (permutations.size() == n) {
            int ret = 0;
            for (int i = 0; i < permutations.size(); i++) {
                if (i == 0) ret += dist[0][permutations.get(i)];
                else ret += dist[permutations.get(i - 1)][permutations.get(i)];
            }
            ret += dist[permutations.get(permutations.size() - 1)][1];
            if (ret < ans) ans = ret;
            return;
        }
        for (int i = 2; i <= n+1; i++) {
            if (chk[i] == 0) {
                chk[i] = 1;
                permutations.add(i);
                go();
                chk[i] = 0;
                permutations.pollLast();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tcase; t++) {
            n = Integer.parseInt(br.readLine());
            nodes = new Node[n + 2];
            chk = new int[n + 2];
            dist = new int[n + 2][n + 2];
            permutations = new LinkedList<>();
            ans = Integer.MAX_VALUE;
            for(int i = 0; i < n + 2; i++) nodes[i] = new Node();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n + 2; i++) {
                nodes[i].x = Integer.parseInt(st.nextToken());
                nodes[i].y = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    if (i == j) continue;
                    dist[i][j] = Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y);
                }
            }

            go();

            System.out.printf("#%d %d\n", t, ans);
        }
    }
}
