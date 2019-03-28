//https://www.acmicpc.net/problem/2458

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N, M;
    static int[][] adjMat;
    static int[] answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] NM = br.readLine().split(" ");
        N = Integer.parseInt(NM[0]);    // 학생 수
        M = Integer.parseInt(NM[1]);    // 두 학생을 비교한 횟수
        adjMat = new int[N + 1][N + 1];
        answer = new int[N + 1];

        for (int i = 0; i < M; ++i) {
            String[] s = br.readLine().split(" ");
            int r = Integer.parseInt(s[0]);
            int c = Integer.parseInt(s[1]);
            adjMat[r][c] = 1;
        }

        for (int m = 1; m < N + 1; ++m) {
            for (int s = 1; s < N + 1; ++s) {
                if (m == s) continue;
                for (int e = 1; e < N + 1; ++e) {
                    if (m == e || s == e) continue;
                    if (adjMat[s][m] == 1 && adjMat[m][e] == 1) adjMat[s][e] = 1;
                }
            }
        }

        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                if (adjMat[i][j] == 1) {
                    ++answer[j];
                    ++answer[i];
                }
            }
        }

        int result = 0;
        for (int i = 1; i < N + 1; ++i) {
            if (answer[i] == N - 1) ++result;
        }
        System.out.println(result);
    }
}
