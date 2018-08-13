//https://www.acmicpc.net/problem/2748
//

#include <cstdio>

int n;
long long memo[91];

long long go(int now) {
	if (now == 0) return 0;
	if (now <= 2) return 1;
	if (memo[now] != 0) return memo[now];
	return memo[now] = go(now - 1) + go(now - 2);
}

int main(void) {
	scanf("%d", &n);
	printf("%lld\n", go(n));
	return 0;
}
