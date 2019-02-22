//https://www.acmicpc.net/problem/1063

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private final static int[] dr = {0, 0, 1, -1, -1, -1, 1, 1};
    private final static int[] dc = {1, -1, 0, 0, 1, -1, 1, -1};
    private static Pair[] pairs;

    private static class Pair {
        int r, c;

        public Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");

        pairs = new Pair[2];
        for (int i = 0; i < 2; i++) {
            pairs[i] = new Pair(8 - (tmp[i].charAt(1) - '0'), tmp[i].charAt(0) - 'A');
        }
        int n = Integer.parseInt(tmp[2]);

        for (int i = 0; i < n; i++) {
            String cmd = br.readLine();
            int d = 0;
            if (cmd.equals("R")) d = 0;
            else if (cmd.equals("L")) d = 1;
            else if (cmd.equals("B")) d = 2;
            else if (cmd.equals("T")) d = 3;
            else if (cmd.equals("RT")) d = 4;
            else if (cmd.equals("LT")) d = 5;
            else if (cmd.equals("RB")) d = 6;
            else if (cmd.equals("LB")) d = 7;

            int nr = pairs[0].r + dr[d];
            int nc = pairs[0].c + dc[d];
            if (isOutOfArea(nr, nc)) continue;

            if (nr == pairs[1].r && nc == pairs[1].c) {
                int nnr = nr + dr[d];
                int nnc = nc + dc[d];
                if (isOutOfArea(nnr, nnc)) continue;
                pairs[1].r = nnr;
                pairs[1].c = nnc;
                pairs[0].r = nr;
                pairs[0].c = nc;
            } else {
                pairs[0].r = nr;
                pairs[0].c = nc;
            }
        }
        for (int i = 0; i < 2; i++) {
            System.out.println((char) (pairs[i].c + 'A') + "" + (8 - pairs[i].r));
        }
    }

    private static boolean isOutOfArea(int r, int c) {
        if (r < 0 || c < 0 || r > 7 || c > 7) return true;
        return false;
    }
}
