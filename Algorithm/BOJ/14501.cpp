//https://www.acmicpc.net/problem/14501
//http://1ilsang.blog.me/221355746639

#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int ans;
int chk[17];

void go(int lo, int cnt) {
	if (lo > n + 1 || chk[lo] == 1) {
		return;
	}
	if (cnt > ans) {
		ans = cnt;
	}
	chk[lo] = 1;
	go(lo + v[lo - 1].first, cnt + v[lo - 1].second);
	chk[lo] = 0;
	go(lo + 1, cnt);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a, b });
	}
	go(1, 0);
	printf("%d\n", ans);
	return 0;
}
