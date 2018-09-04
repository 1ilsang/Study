//https://www.acmicpc.net/problem/10817

#include <cstdio>

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if ((a >= b && b >= c && a >= c) || (a <= b && b <= c && a <= c)) {
		printf("%d\n", b);
	}
	else if ((b >= a && a >= c && b >= c) || (b <= a && a <= c && b <= c)) {
		printf("%d\n", a);
	}
	else if ((a >= c && c >= b && a >= b) || (a <= c && c <= b && a <= b)) {
		printf("%d\n", c);
	}
	return 0;
}
