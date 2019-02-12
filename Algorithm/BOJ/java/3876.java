//https://www.acmicpc.net/problem/3876
//http://1ilsang.blog.me/221463846212

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Main {
    private static String endCmd, cmd;
    private static HashMap<String, String> map, chk;

    private static class Node {
        String str;
        int p;

        private Node(String str, int p) {
            this.str = str;
            this.p = p;
        }
    }

    private static int bfs() {
        int ret = -1;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(cmd, 0));

        while (!queue.isEmpty()) {
            String now = queue.peek().str;
            int p = queue.peek().p;
            queue.poll();

            if (now.equals(endCmd)) {
                ret = p;
                break;
            }
            if (now.length() > 10) continue;

            for (Map.Entry e : map.entrySet()) {
                String tmp = now.replace((String) e.getKey(), (String) e.getValue());
                if (!chk.containsKey(tmp)) {
                    chk.put(tmp, "1");
                    queue.offer(new Node(tmp, p + 1));
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;

            map = new HashMap<>();
            chk = new HashMap<>();

            for (int i = 0; i < n; i++) {
                String[] in = br.readLine().split(" ");
                map.put(in[0], in[1]);
            }
            cmd = br.readLine();
            endCmd = br.readLine();

            System.out.println(bfs());
        }
        br.close();
    }
}
