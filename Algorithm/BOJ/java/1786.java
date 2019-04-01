//https://www.acmicpc.net/problem/1786
//http://1ilsang.blog.me/221502910608


/*
 * Rabin-Karp
 *
 */
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String target = sc.nextLine();
        String pattern = sc.nextLine();
        int targetSize = target.length();
        int patternSize = pattern.length();
        if (targetSize < patternSize) System.out.println(0);
        else {
            final int D = 31;
            final int MOD = (int)1e9 + 7;
            long head = 1;
            long patternHash = 0;
            long nowHash = 0;

            for (int i = 0; i < patternSize; i++) {
                patternHash = (patternHash * D + pattern.charAt(i)) % MOD;
                nowHash = (nowHash * D + target.charAt(i)) % MOD;
                if (i != 0) head = (head * D) % MOD;
            }
            LinkedList<Integer> ans = new LinkedList<>();
            for (int i = 0; i <= targetSize - patternSize; i++) {
                if(nowHash == patternHash) ans.add(i + 1);
                if(i + patternSize == targetSize) break;
                nowHash = (D * (nowHash - target.charAt(i) * head) + target.charAt(i + patternSize)) % MOD;
                if(nowHash < 0) nowHash += MOD;
            }
            System.out.println(ans.size());
            for(Integer e: ans) System.out.print(e + " ");
        }
    }
}


/*
 * KMP

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String target = br.readLine();
        int targetSize = target.length();
        int strSize = str.length();
        int[] pi = new int[targetSize];

        for(int i = 1, j = 0; i < pi.length; i++) {
            while(j > 0 && target.charAt(i) != target.charAt(j)) j = pi[j - 1];
            if(target.charAt(i) == target.charAt(j)) pi[i] = ++j;
            else pi[i] = 0;
        }
        LinkedList<Integer> ans = new LinkedList<>();
        for(int i = 0, j = 0; i < strSize; i++) {
            while(j > 0 && str.charAt(i) != target.charAt(j)) j = pi[j - 1];
            if(str.charAt(i) == target.charAt(j)) {
                if(j == targetSize - 1) {
                    ans.add(i - targetSize + 2);
                    j = pi[j];
                } else j++;
            }
        }
        System.out.println(ans.size());
        for(Integer e: ans) System.out.print(e + " ");
    }
}
*/
