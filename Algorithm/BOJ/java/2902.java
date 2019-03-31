//https://www.acmicpc.net/problem/2902

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        StringBuilder sb = new StringBuilder();
        sb.append(str.charAt(0));
        for(int i = 1 ; i < str.length() - 1;i++) {
            if(str.charAt(i) == '-') sb.append(str.charAt(i + 1));
        }
        System.out.println(sb);
    }
}
