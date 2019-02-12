//https://www.acmicpc.net/problem/15654

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    private static int n, m;
    private static int[] list, chk;
    private static LinkedList<Integer> ans = new LinkedList<>();

    private static void go() {
        if(ans.size() == m) {
            for(int i = 0 ; i < ans.size(); i++) {
                System.out.print(ans.get(i) + " ");
            }
            System.out.println();
            return;
        }
        for(int i = 0 ; i < list.length; i++) {
            if(chk[i] == 0) {
                chk[i] = 1;
                ans.add(list[i]);
                go();
                ans.pollLast();
                chk[i] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        list = new int[n];
        chk = new int[n];
        tmp = br.readLine().split(" ");
        for(int i = 0 ; i < n; i++) list[i] = Integer.parseInt(tmp[i]);
        Arrays.sort(list);
        go();
    }
}
