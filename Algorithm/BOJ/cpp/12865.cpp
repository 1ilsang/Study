//https://www.acmicpc.net/problem/12865
//http://1ilsang.blog.me/221438509136

#include <cstdio>
#include <algorithm>

using namespace std;

bool toggle = false;
int w[101];
int v[101];
int dp[100001][2];
int n, k;

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - w[i] < 0) dp[j][toggle] = dp[j][!toggle];
            else dp[j][toggle] = max(dp[j][!toggle], dp[j - w[i]][!toggle] + v[i]);
        }
        toggle = !toggle;
    }
    printf("%d\n", max(dp[k][toggle], dp[k][!toggle]));
    return 0;
}
