//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int k = Integer.parseInt(br.readLine());
            String str = br.readLine();
            String[] suffixArray = new String[str.length()];
            int[] LCP = new int[str.length()];

            for (int i = 0; i < str.length(); i++) suffixArray[i] = str.substring(i);

            Arrays.sort(suffixArray);
            LCP[0] = 0;
            for (int i = 1; i < str.length(); i++) {
                String prev = suffixArray[i - 1];
                String cur = suffixArray[i];
                int j = 0;
                while (j < prev.length() && j < cur.length() && prev.charAt(j) == cur.charAt(j)) j++;
                LCP[i] = j;
            }

            int subCnt = 0;
            for (int i = 0; i < str.length(); i++) {
                subCnt += suffixArray[i].length() - LCP[i];
                if(subCnt >= k) {
                    System.out.printf("#%d %s\n", t, suffixArray[i].substring(0, suffixArray[i].length() - (subCnt - k)));
                    break;
                }
            }
            if(subCnt < k) System.out.printf("#%d none\n", t);
        }
    }
}
