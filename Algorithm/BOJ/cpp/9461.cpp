//https://www.acmicpc.net/problem/9461
//http://1ilsang.blog.me/221436841486

#include <cstdio>

int main(void) {
    int tcase;
    long long dp[102];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    for (int i = 6; i < 101; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
