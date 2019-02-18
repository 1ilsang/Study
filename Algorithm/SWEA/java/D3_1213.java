//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14P0c6AAUCFAYi

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int t = 1; t < 11; t++) {
            int dump = Integer.parseInt(br.readLine());
            String target = br.readLine();
            String str = br.readLine();
            int ans = 0;
            for(int i = 0; i < str.length(); i++) {
                boolean flag = true;
                if(i == str.length() - 1 && target.length() > 0) continue;
                for(int j = 0 ; j < target.length(); j++) {
                    if(str.charAt(i + j) != target.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
            System.out.printf("#%d %d\n", t, ans);
        }
        br.close();
    }
}
