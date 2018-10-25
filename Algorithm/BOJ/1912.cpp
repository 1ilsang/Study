//https://www.acmicpc.net/problem/1912
//http://1ilsang.blog.me/221384920352

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long ans;
long long area[100002];
long long dp[100002];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lld", &area[i]);
	ans = dp[0] = area[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(area[i], dp[i - 1] + area[i]);
		if (ans < dp[i]) ans = dp[i];
	}
	printf("%lld\n", ans);
	return 0;
}
