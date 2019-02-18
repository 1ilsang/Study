//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for(int t = 1; t <= tcase;t++) {
            LinkedList<String> list = new LinkedList<>();
            String str = br.readLine();
            String tmp = "";
            int ans = 0;
            for(int i = 0; i < str.length(); i++) {
                tmp += str.charAt(i);
                list.add(tmp);
            }
            for(String e: list) {
                boolean flag = true;
                int k = 0;
                for(int i = 0; i < str.length(); i++) {
                    if(str.charAt(i) != e.charAt(k++)) {
                        flag = false;
                        break;
                    }
                    if(k == e.length()) k = 0;
                }
                if(flag) {
                    ans = e.length();
                    break;
                }
            }
            System.out.printf("#%d %d\n", t, ans);
        }
            br.close();
    }
}
/*
3
KOREAKOREAKOREAKOREAKOREAKOREA
SAMSUNGSAMSUNGSAMSUNGSAMSUNGSA
GALAXYGALAXYGALAXYGALAXYGALAXY
 */
