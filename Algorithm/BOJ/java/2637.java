//https://www.acmicpc.net/problem/2637

import java.io.*;
import java.util.LinkedList;

public class Solution {
    private static int n, m;
    private static LinkedList<Node>[] nodes;
    private static int[] ans, chk;

    private static class Node {
        int y, k;
        private Node(int y, int k) {
            this.y = y;
            this.k = k;
        }
    }

    private static void getNodes(int now, int nx) {
        for (int i = 0; i < nodes[now].size(); i++) {
            Node cur = nodes[now].get(i);
            if(chk[cur.y] == 0) ans[cur.y] += cur.k * nx;
            else getNodes(cur.y, cur.k * nx);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        nodes = new LinkedList[n + 1];
        ans = new int[n + 1];
        chk = new int[n + 1];

        for (int i = 0; i <= n; i++) nodes[i] = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            String[] cmd = br.readLine().split(" ");
            int x = Integer.parseInt(cmd[0]);
            int y = Integer.parseInt(cmd[1]);
            int k = Integer.parseInt(cmd[2]);
            chk[x] = 1;
            nodes[x].add(new Node(y, k));
        }

        getNodes(n, 1);

        for (int i = 1; i <= n; i++) {
            if(chk[i] == 0) System.out.println(i + " " + ans[i]);
        }

        br.close();
    }
}
