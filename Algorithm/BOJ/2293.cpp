//https://www.acmicpc.net/problem/2293
//http://1ilsang.blog.me/221340766367

#include <cstdio>

int coin[101];
int dp[10001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
				//	printf("%d %d | %d %d\n", i, j, j - coin[i], dp[j]);
			}
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}
