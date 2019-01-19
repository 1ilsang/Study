//https://www.acmicpc.net/problem/1904
//http://1ilsang.blog.me/221338617156

#include <cstdio>

int d[1000001];

int main() {
	int n;
	d[1] = 1;
	d[2] = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}
	printf("%d\n", d[n]);
	return 0;
}
