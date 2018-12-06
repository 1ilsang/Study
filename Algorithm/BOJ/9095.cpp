//https://www.acmicpc.net/problem/9095
//http://1ilsang.blog.me/221413697150

#include <cstdio>

int main(void) {
    int n;
    int dp[100002];
    int tcase;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    scanf("%d", &tcase);
    for (int i = 0; i < tcase; i++) {
        scanf(" %d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
