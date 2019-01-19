//https://www.acmicpc.net/problem/14888
//http://1ilsang.blog.me/221354590689

#include <cstdio>

int n;
int num[12];
int oper[12];
int maxAns = -9999999999;
int minAns = 9999999999;

void go(int lo, int v) {
	if (lo == n - 1) {
		if (minAns > v) minAns = v;
		if (maxAns < v) maxAns = v;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i] -= 1;
			if (i == 0) go(lo + 1, v + num[lo + 1]);
			if (i == 1) go(lo + 1, v - num[lo + 1]);
			if (i == 2) go(lo + 1, v * num[lo + 1]);
			if (i == 3) go(lo + 1, v / num[lo + 1]);
			oper[i]++;
		}
	}
}

int main(void) {
	int d = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	go(0, num[0]);
	printf("%d\n%d\n", maxAns, minAns);
	return 0;
}
