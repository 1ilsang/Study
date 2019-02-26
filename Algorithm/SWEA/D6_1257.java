//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int n = Integer.parseInt(br.readLine());
            String str = br.readLine();
            Set<String> list = new HashSet<>();

            for (int i = 0; i < str.length(); i++) {
                for (int j = i; j < str.length() + 1; j++) {
                    list.add(str.substring(i, j));
                }
            }
            String[] lista = new String[list.size()];
            int cnt = 0;
            for(String e : list) lista[cnt++] = e;
            Arrays.sort(lista);
            System.out.printf("#%d %s\n", t, lista[n]);
        }
    }
}
