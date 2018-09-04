//https://www.acmicpc.net/problem/10953

#include <cstdio>

int main(void) {
	int a, b, t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
