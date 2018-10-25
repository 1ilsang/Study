//https://www.acmicpc.net/problem/2231
//http://1ilsang.blog.me/221384947376

#include <cstdio>

int main(void) {
	int n;
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int tmp = i, num = i;
		while (tmp) {
			num += tmp % 10;
			tmp /= 10;
		}
		if (num == n) {
			ans = i; break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
