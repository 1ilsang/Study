//https://www.acmicpc.net/problem/11723

import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        int list = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] tmp = br.readLine().split(" ");
            int num;
            if (tmp[0].equals("all")) list = (1 << 21) - 1;
            else if (tmp[0].equals("empty")) list = 1 >> 21;
            else {
                num = Integer.parseInt(tmp[1]);
                if (tmp[0].equals("add")) list |= 1 << num;
                else if (tmp[0].equals("remove")) list &= ~(1 << num);
                else if (tmp[0].equals("check")) bw.write(((list & (1 << num)) > 0 ? 1 : 0) + "\n");
                else list ^= 1 << num;
            }
        }
        bw.close();
    }
}
