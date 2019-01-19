//https://www.acmicpc.net/problem/1149

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1002][3];
int dp[1002][3];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    return 0;
}
