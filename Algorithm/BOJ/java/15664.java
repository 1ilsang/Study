//https://www.acmicpc.net/problem/15664

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static Set<String> set;
    private static LinkedList<Integer> list;
    private static int[] arr;
    private static int n, m;

    private static void go(int lo, int cur) {
        if(lo == m) {
            String tmp = "";
            for(int i = 0; i < list.size(); i++) tmp += list.get(i);
            if(set.contains(tmp)) return;
            set.add(tmp);
            for(int i = 0 ; i < list.size(); i++) System.out.print(list.get(i) + " ");
            System.out.println();
            return;
        }

        for(int i = cur; i < n; i++) {
            list.add(arr[i]);
            go(lo + 1, i + 1);
            list.pollLast();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        set = new HashSet<>();
        list = new LinkedList<>();

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < n ; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        go(0, 0);
    }
}
