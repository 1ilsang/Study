//https://www.acmicpc.net/problem/10864

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        LinkedList<Integer>[] list = new LinkedList[n+1];
        for(int i = 1 ; i <= n; i++) list[i] = new LinkedList<>();
        for(int i = 0 ; i < m; i++) {
            tmp = br.readLine().split(" ");
            list[Integer.parseInt(tmp[0])].add(Integer.parseInt(tmp[1]));
            list[Integer.parseInt(tmp[1])].add(Integer.parseInt(tmp[0]));
        }
        for(int i = 1; i <= n; i++) System.out.println(list[i].size());
    }
}
