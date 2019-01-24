//https://www.acmicpc.net/problem/11729

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    private static BufferedWriter bw;

    private static int myPow(int n, int m) {
        if(m == 0) return 1;
        int ret = myPow(n, m / 2);
        if(m % 2 == 0) ret *= ret;
        else ret *= ret * n;
        return ret;
    }

    private static void hanoi(int n, int from, int by, int to) throws IOException {
        if (n == 1) {
            bw.write(from + " " + to + "\n");
            return;
        }
        hanoi(n - 1, from, to, by);
        bw.write(from + " " + to + "\n");
        hanoi(n - 1, by, from, to);
    }

    public static void main(String[] args) throws IOException {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = myPow(2, n) - 1;
        bw.write(cnt + "\n");
        hanoi(n, 1, 2, 3);
        bw.close();
    }
}
