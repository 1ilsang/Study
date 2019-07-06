//https://www.acmicpc.net/problem/5217

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < tcase; t++) {
            int n = Integer.parseInt(br.readLine().trim());
            StringBuilder str = new StringBuilder();
            String tmp = "Pairs for " + n + ":";
            str.append(tmp);
            for (int i = 1; i <= n / 2; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (i + j == n) {
                        String tmp2 = "";
                        if(i == 1) tmp2 = " ";
                        tmp2 += i + " " + j + ", ";
                        str.append(tmp2);
                    }
                }
            }
            int comIdx  = str.lastIndexOf(",");
            if(comIdx != -1) {
                str.delete(comIdx, comIdx + 1);
            }
            System.out.println(str);
        }
    }
}

