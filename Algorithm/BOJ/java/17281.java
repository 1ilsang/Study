//https://www.acmicpc.net/problem/17281
//http://1ilsang.blog.me/221605310171

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    private static int n;
    private static int[][] area;
    private static boolean[] chk;
    private static int[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        area = new int[n][9];
        chk = new boolean[9];
        list = new  int[9];

        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < 9; j++) area[i][j] = Integer.parseInt(str[j]);
        }
        chk[3] = true;
        list[3] = 0;

        System.out.println(go(1));
    }

    private static int go(int playerNum) {
        int ret = Integer.MIN_VALUE;

        if (playerNum == 9) return getScore();

        for (int i = 0; i < 9; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            list[i] = playerNum;
            ret = Math.max(ret, go(playerNum + 1));
            chk[i] = false;
        }

        return ret;
    }

    private static int getScore() {
        int ret = 0;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            int cnt  = 1;
            int outCnt = 0;

            while(true) {
                int cmd = area[i][list[cur++]];

                if(cmd == 0) outCnt++;
                else {
                    cnt <<= cmd;
                    cnt |= 1;
                }

                if(cur == 9) cur = 0;
                if(outCnt == 3) break;

                if(cnt > 15) {
                    for(int k = 1 << 4; k < 256; k <<= 1)  {
                        if((cnt & k) == 0) continue;
                        cnt &= ~k;
                        ret++;
                    }
                }
            }
        }

        return ret;
    }
}
