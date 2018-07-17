//https://www.acmicpc.net/problem/1158
//http://1ilsang.blog.me/221320848817

#include <stdio.h>
#include <queue>
using namespace std;

queue<int> q;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	printf("<");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		if (i == n - 1) {
			printf("%d>\n", q.front());
			q.pop();
		}
		else {
			printf("%d, ", q.front());
			q.pop();
		}
	}
	return 0;
}
