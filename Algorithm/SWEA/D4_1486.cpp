//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b7Yf6ABcBBASw&categoryId=AV2b7Yf6ABcBBASw&categoryType=CODE
//http://1ilsang.blog.me/221313909212

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[21];
int check[21];
int ans = 22000000, n, b;

void go(int now, int nowSum) {
	if (now > n) return;
	if (nowSum >= b) {
		ans = min(ans, nowSum);
	}
	go(now + 1, nowSum + arr[now]);
	go(now + 1, nowSum);
}

int main(void) {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &b);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		go(0, 0);
		printf("#%d %d\n", cnt++, ans - b);
		ans = 22222222;
	}
	return 0;
}