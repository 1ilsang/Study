//https://www.acmicpc.net/problem/13458
//http://1ilsang.blog.me/221356850962

#include <cstdio>

long long arr[1000001];
long long n, b, c;
long long ans;

int main(void) {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld %lld", &b, &c);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		ans++;
		arr[i] = arr[i] - b;
		if (arr[i] <= 0) arr[i] = 0;
		else if(arr[i] % c == 0) {
			ans += (arr[i] / c);
		}
		else if (arr[i] % c > 0) {
			ans += (arr[i] / c + 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
