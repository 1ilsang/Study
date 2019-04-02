//http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=625&sca=4040

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n, m, ans;
    private static int[] parents;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        parents = new int[n + 1];
        Arrays.fill(parents, -1);
        Node[] list = new Node[m];
        for(int i = 0 ; i < m ; i++) {
            tmp = br.readLine().split(" ");
            int a = Integer.parseInt(tmp[0]);
            int b = Integer.parseInt(tmp[1]);
            int c = Integer.parseInt(tmp[2]);
            list[i] = new Node(a, b, c);
        }
        Arrays.sort(list);
        for(Node e: list) if(union(e.from, e.to)) ans += e.cost;
        System.out.println(ans);
    }

    private static boolean union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if(aRoot == bRoot) return false;
        parents[bRoot] = aRoot;
        return true;
    }

    private static int find(int a) {
        if(parents[a] == -1) return a;
        return parents[a] = find(parents[a]);
    }
    private static class Node implements Comparable<Node> {
        int from, to;
        long cost;

        public Node(int from, int to, long cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Long.compare(o.cost, this.cost);
        }
    }
}
