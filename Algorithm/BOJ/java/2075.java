//https://www.acmicpc.net/problem/2075

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> queue =new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0 ; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < n; j++) queue.offer(Integer.parseInt(st.nextToken()));
        }

        for(int i = 0 ; i < n - 1; i++) queue.poll();
        System.out.println(queue.poll());
    }
}
