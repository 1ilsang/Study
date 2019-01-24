//https://www.acmicpc.net/problem/2446

import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n * 2; j++) {
                if (i >= j) bw.write(" ");
                else if(j > n * 2 - i - 1) continue;
                else bw.write("*");
            }
            bw.write("\n");
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < n * 2; j++) {
                if (n - 2 - i >= j) bw.write(" ");
                else if(j > (n + i + 1)) continue;
                else bw.write("*");
            }
            if(i < n - 2) bw.write("\n");
        }

        br.close();
        bw.close();
    }
}
