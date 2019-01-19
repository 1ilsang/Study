//https://www.acmicpc.net/problem/11720

#include <cstdio>

int main(void) {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%1d", &tmp);
		ans += tmp;
	}
	printf("%d\n", ans);
	return 0;
}
