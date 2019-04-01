//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbrg9uabZsDFAWQ

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class Solution {
    private static int n;
    private static int[][] area;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine().trim());
        for (int t = 1; t <= tcase; t++) {
            String[] tmp = br.readLine().split(" ");
            n = Integer.parseInt(tmp[0]);
            String cmd = tmp[1];
            area = new int[n][n];
            for (int i = 0; i < n; i++) {
                tmp = br.readLine().split(" ");
                for (int j = 0; j < n; j++) area[i][j] = Integer.parseInt(tmp[j]);
            }
            go(cmd);
            System.out.printf("#%d\n", t);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) System.out.print(area[i][j] + " ");
                System.out.println();
            }
        }
    }

    private static void go(String cmd) {
        int d = -1;
        if (cmd.equals("up")) d = 0;
        else if (cmd.equals("down")) d = 1;
        else if (cmd.equals("left")) d = 2;
        else if (cmd.equals("right")) d = 3;

        if (d == -1) return;

        for (int i = 0; i < n; i++) {
            LinkedList<Integer> vList = new LinkedList<>();
            for (int j = 0; j < n; j++) {
                int tmp = d < 2 ? area[j][i] : area[i][j];
                if (tmp != 0) vList.add(tmp);
            }
            if (d == 1 || d == 3) Collections.reverse(vList);
            LinkedList<Integer> list = new LinkedList<>();
            for (int j = 0; j < vList.size(); j++) {
                if (j  + 1 < vList.size() && vList.get(j).equals(vList.get(j + 1))) {
                    list.add(vList.get(j) * 2);
                    j++;
                } else list.add(vList.get(j));
            }
            for (int j = list.size(); j < n; j++) list.add(0);
            if (d == 1 || d == 3) Collections.reverse(list);

            for (int j = 0; j < n; j++) {
                if (d < 2) area[j][i] = list.pollFirst();
                else area[i][j] = list.pollFirst();
            }
        }
    }
}
