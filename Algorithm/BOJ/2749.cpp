//https://www.acmicpc.net/problem/2749

#include <cstdio>

typedef long long ll;
const int MOD = 1000000;
const int P = MOD / 10 * 15;

int main(void) {
    int fibo[P] = {0, 1};
    ll n;
    scanf("%lld", &n);
    for (int i = 2; i < P; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
    printf("%d\n", fibo[n % P]);
    return 0;
}
