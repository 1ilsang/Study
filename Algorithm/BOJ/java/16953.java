//https://www.acmicpc.net/problem/16953
//http://1ilsang.blog.me/221481577668

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int target = Integer.parseInt(tmp[1]);
        System.out.println(bfs(tmp[0], target));
    }
    private static int bfs(String n, int target) {
        int ret = -1;
        Queue<Node> queue = new LinkedList<>();
        Set<String> set = new HashSet<>();
        queue.offer(new Node(n, 1));
        set.add(n);
        while(!queue.isEmpty()) {
            String nowStr = queue.peek().n;
            int p = queue.peek().p;
            long now = Long.parseLong(nowStr);
            queue.poll();
            if(now > 1000000001) continue;
            else if(now == target) {
                ret = p;
                break;
            }
            String a = nowStr + "1";
            String b = (now * 2) + "";
            if(!set.contains(a)) {
                set.add(a);
                queue.offer(new Node(a, p + 1));
            }
            if(!set.contains(b)) {
                set.add(b);
                queue.offer(new Node(b, p + 1));
            }
        }
        return ret;
    }
    private static class Node {
        String n;
        int p;

        public Node(String n, int p) {
            this.n = n;
            this.p = p;
        }
    }
}
