//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15B1cKAKwCFAYD
//http://1ilsang.blog.me/221491864280

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    private static LinkedList<Integer>[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int t = 1; t <= 10; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            Set<String> set = new HashSet<>();
            int n = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken());
            list = new LinkedList[101];
            for (int i = 0; i < 101; i++) list[i] = new LinkedList<>();
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                String token = from + " " + to;
                if (!set.contains(token)) set.add(token);
            }
            for (String e : set) {
                String[] tmp = e.split(" ");
                list[Integer.parseInt(tmp[0])].add(Integer.parseInt(tmp[1]));
            }
            System.out.printf("#%d %d\n", t, bfs(start));
        }
    }

    private static int bfs(int start) {
        int lastTime = -1;
        int lastTimeNode = -1;
        boolean[] visit = new boolean[101];

        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(start, 0));
        visit[start] = true;

        while(!queue.isEmpty()) {
            int now = queue.peek().now;
            int nowTime = queue.peek().cost;
            queue.poll();

            if(lastTime == nowTime && lastTimeNode < now) lastTimeNode = now;
            else if(lastTime < nowTime) {
                lastTime = nowTime;
                lastTimeNode = now;
            }

            for(int i = 0 ; i < list[now].size(); i++) {
                int next = list[now].get(i);
                if(!visit[next]) {
                    visit[next] = true;
                    queue.offer(new Node(next, nowTime + 1));
                }
            }
        }

        return lastTimeNode;
    }

    private static class Node {
        int now, cost;

        public Node(int now, int cost) {
            this.now = now;
            this.cost = cost;
        }
    }
}
