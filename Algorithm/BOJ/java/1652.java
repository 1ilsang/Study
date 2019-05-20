//http://blog.naver.com/1ilsang/221542104854
//https://www.acmicpc.net/problem/1652

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int row  = 0, col = 0;
        char[][] area = new char[n][n];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) area[i][j] = str.charAt(j);
        }
        boolean flag = true;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n - 1; j++) {
                if(flag && area[i][j] == area[i][j + 1] && area[i][j] == '.') {
                    row++;
                    flag = false;
                }
                else if(area[i][j] == 'X') flag = true;
            }
            flag = true;
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n - 1; j++) {
                if(flag && area[j][i] == area[j + 1][i] && area[j][i] == '.') {
                    col++;
                    flag =  false;
                }
                else if(area[j][i] == 'X') flag = true;
            }
            flag = true;
        }
        System.out.println(row + " " + col);
    }
}
