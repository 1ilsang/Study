//https://www.acmicpc.net/problem/16987

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int n;
    private static Node[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        list = new Node[n];
        for(int i = 0 ; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            list[i] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        System.out.println(backTracking(0, 0));
    }

    private static int backTracking(int lo, int bn) {
        int ret = 0;
        if(lo == n) return bn;
        if(list[lo].s <= 0 || bn == n - 1) return backTracking(lo + 1, bn);

        for(int i = 0 ; i < n; i++) {
            if(i == lo || list[i].s <= 0) continue;
            list[i].s -= list[lo].w;
            list[lo].s -= list[i].w;
            if(list[i].s <= 0) bn++;
            if(list[lo].s <= 0) bn++;
            ret = Math.max(ret, backTracking(lo + 1, bn));
            if(list[i].s <= 0) bn--;
            if(list[lo].s <= 0) bn--;
            list[i].s += list[lo].w;
            list[lo].s += list[i].w;
        }
        return ret;
    }

    private static class Node{
        int s, w;

        public Node(int s, int w) {
            this.s = s;
            this.w = w;
        }
    }
}
