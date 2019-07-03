//https://www.acmicpc.net/problem/5532
//http://1ilsang.blog.me/221577045697

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int L = Integer.parseInt(br.readLine());
        int A = Integer.parseInt(br.readLine());
        int B = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        int D = Integer.parseInt(br.readLine());

        int a = A % C == 0 ? A / C : A / C + 1;
        int b = B % D == 0 ? B / D : B / D + 1;
        int ans = a > b ? a : b;
        System.out.println(L - ans);
    }
}
