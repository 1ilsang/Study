//https://www.acmicpc.net/problem/2163
//http://1ilsang.blog.me/221429283900

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 302;

int dp[MAX_N][MAX_N];
int ans;

int go(int n, int m) {
    int &ret = dp[n][m];
    if (ret != -1) return ret;
    if (n == 0 || m == 0 || (n == 1 && m == 1)) return 0;
    ans++;
    return ret = go(n - 1, m) + go(n, m - 1) + 1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    go(n, m);
    printf("%d\n", ans);
    return 0;
}
