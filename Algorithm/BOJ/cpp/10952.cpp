//https://www.acmicpc.net/problem/10952

#include <cstdio>

int main(void) {
	int a, b;
	while (true) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
		if (a == 0 && b == 0) break;
	}
	return 0;
}
