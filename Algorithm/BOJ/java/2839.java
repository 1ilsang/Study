//https://www.acmicpc.net/problem/2839
//http://1ilsang.blog.me/221577119115

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int ans = -1;

        for (int i = 0; i <= n; i += 5) {
            for (int j = 0; j <= n; j += 3) {
                if (n - i - j == 0) ans = i / 5 + j  / 3;
            }
        }

        System.out.println(ans);
    }
}
