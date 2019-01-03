//https://www.acmicpc.net/problem/1793
//http://1ilsang.blog.me/221433364110

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 252;

vector<string> dp;

int main(void) {
    string str;
    dp.resize(MAX_N, "");
    int n;
    dp[0] = "1";
    dp[1] = "1";
    dp[2] = "3";

    for (int i = 3; i <= MAX_N; i++) {
        str = "";
        int a, b, c, d, j, jj;
        d = 0;
        j = (int) dp[i - 1].size() - 1;
        jj = (int) dp[i - 2].size() - 1;
        while (true) {
            if(j < 0) break;
            a = dp[i - 1][j--] - '0';
            if(jj >= 0) b = dp[i - 2][jj--] - '0';
            else b = 0;

            c = a + b * 2 + d;

            if (c > 9) d = c / 10, c %= 10;
            else d = 0;

            str += c + '0';
            if(j == -1 && d > 0) str += d + '0';
        }
        reverse(str.begin(), str.end());
        dp[i] = str;
    }

    while (scanf("%d", &n) != EOF) cout << dp[n] << endl;
    return 0;
}
