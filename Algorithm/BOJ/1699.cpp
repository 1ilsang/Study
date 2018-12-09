//https://www.acmicpc.net/problem/1699
//http://1ilsang.blog.me/221415667120

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 987654321;
int dp[317][100002];

int go(int coin, int money) {
    int &ref = dp[coin][money];
    if (coin < 1 || money < 0) return INF;
    if (money == 0) return 0;
    if (ref > 0) return ref;
    return ref = min(go(coin - 1, money), go(coin, money - coin * coin) + 1);
}

int main(void) {
    int n, k;
    scanf("%d", &k);
    n = sqrt(k);
    printf("%d\n", go(n, k));
    return 0;
}
