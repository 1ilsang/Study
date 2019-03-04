//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWczm7QaACgDFAWn

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine().trim());
        for(int t = 1; t<= tcase; t++) {
            int[] line = new int[5005];
            int n = Integer.parseInt(br.readLine().trim());
            for(int i = 0 ; i < n; i++) {
                String[] tmp = br.readLine().split(" ");
                int a = Integer.parseInt(tmp[0]);
                int b = Integer.parseInt(tmp[1]);
                for(int j = a; j <= b; j++) line[j]++;
            }
            int p = Integer.parseInt(br.readLine());
            System.out.print("#" + t + " ");
            for(int i = 0 ; i < p; i++) {
                int k = Integer.parseInt(br.readLine());
                if(i < p -1) System.out.print(line[k] + " ");
                else System.out.println(line[k]);
            }
        }
    }
}
