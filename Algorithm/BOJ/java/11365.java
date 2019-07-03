//https://www.acmicpc.net/problem/11365
//http://blog.naver.com/1ilsang/221577142648

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder ans = new StringBuilder();
        String str;
        while(true) {
            str = br.readLine();
            if(str.equals("END")) break;
            int len = str.length();
            for(int i = 0; i < len; i++) ans.append(str.charAt(len - i - 1));
            ans.append('\n');
        }
        ans.deleteCharAt(ans.lastIndexOf("\n"));
        System.out.println(ans);
    }
}
