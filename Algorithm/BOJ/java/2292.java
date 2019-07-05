//https://www.acmicpc.net/problem/2292
//http://1ilsang.blog.me/221578539824

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int now = 1;

        for(int i = 0; i <= 166666669; i++) {
            now += i * 6;
            if(n <= now) {
                System.out.println(i + 1);
                break;
            }
        }
    }
}
