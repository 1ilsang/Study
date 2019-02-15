//https://www.acmicpc.net/problem/1759

import java.io.*;
import java.util.*;

public class Main {
    // a, e, i, o, u = 0, 4, 8, 14, 20;
    private static int n, m;
    private static LinkedList<Character> alpha, chk;
    private static HashSet<String> hashSet;
    private static BufferedWriter bw;

    private static void go(int lo) throws IOException {
        if (chk.size() == n) {
            String tmp = "";
            int moFlag = 0;
            int jaFlag = 0;
            for (int i = 0; i < chk.size(); i++) {
                tmp += chk.get(i);
                if (chk.get(i) == 'a' || chk.get(i) == 'e' || chk.get(i) == 'i' || chk.get(i) == 'o' || chk.get(i) == 'u') {
                    moFlag++;
                } else jaFlag++;
            }
            if (jaFlag >= 2 && moFlag >= 1 && !hashSet.contains(tmp)) {
                hashSet.add(tmp);
                bw.write(tmp + '\n');
            }
            return;
        }
        for(int i = lo; i < m; i++) {
            chk.add(alpha.get(i));
            go(i + 1);
            chk.pollLast();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        alpha = new LinkedList();
        chk = new LinkedList();
        hashSet = new HashSet<>();
        char[] input = br.readLine().toCharArray();
        for (int i = 0; i < input.length; i++) if (input[i] != ' ') alpha.add(input[i]);

        Collections.sort(alpha);

        go(0);
        bw.flush();
        bw.close();
        br.close();
    }
}
