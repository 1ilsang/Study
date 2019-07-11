//https://www.acmicpc.net/problem/2580
//https://1ilsang.blog.me/221583576335

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

class Main {
    private static final int n = 9;
    private static boolean escape;
    private static int[][] area = new int[9][9];
    private static boolean[][] chkRow = new boolean[10][10];
    private static boolean[][] chkCol = new boolean[10][10];
    private static boolean[][] chkSqr = new boolean[10][10];
    private static LinkedList<Node> list = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                area[i][j] = Integer.parseInt(str[j]);
                if (area[i][j] == 0) list.add(new Node(i, j));
            }
        }
        setChk();
        go();
    }

    private static void setChk() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] != 0) {
                    chkRow[i][area[i][j]] = true;
                    chkSqr[i / 3 * 3 + j / 3][area[i][j]] = true;
                }
                if (area[j][i] != 0) chkCol[i][area[j][i]] = true;
            }
        }
    }

    private static void go() {
        if (list.size() == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(area[i][j] + " ");
                }
                System.out.println();
            }
            escape = true;
            return;
        }

        Node cur = list.getLast();
        for (int k = 1; k < 10; k++) {
            if (!possibleNumber(cur.r, cur.c, k, false)) continue;
            area[cur.r][cur.c] = k;
            list.removeLast();
            go();
            possibleNumber(cur.r, cur.c, k, true);
            area[cur.r][cur.c] = 0;
            list.addLast(cur);
            if (escape) break;
        }
    }

    private static boolean possibleNumber(int r, int c, int num, boolean option) {
        if (option) {
            chkRow[r][num] = false;
            chkCol[c][num] = false;
            chkSqr[r / 3 * 3 + c / 3][num] = false;
            return true;
        }
        if (chkRow[r][num] || chkCol[c][num] || chkSqr[r / 3 * 3 + c / 3][num]) return false;
        chkRow[r][num] = true;
        chkCol[c][num] = true;
        chkSqr[r / 3 * 3 + c / 3][num] = true;
        return true;
    }

    private static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
