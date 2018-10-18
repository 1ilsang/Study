//https://www.acmicpc.net/problem/14501
//http://1ilsang.blog.me/221355746639

//2018.10
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int T[20], P[20];

int go(int lo, int price) {
	int ret = 0;
	if (lo > n) return price;
	if(lo + T[lo] <= n + 1) ret = max(ret, go(lo + T[lo], price + P[lo]));
	ret = max(ret, go(lo + 1, price));
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &T[i], &P[i]);
	printf("%d\n", go(1, 0));
	return 0;
}

/////////////////////////////
//2018.09
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int n;
//vector<pair<int, int>> v;
//int ans;
//int chk[17];
//
//void go(int lo, int cnt) {
//	if (lo > n + 1 || chk[lo] == 1) {
//		return;
//	}
//	if (cnt > ans) {
//		ans = cnt;
//	}
//	chk[lo] = 1;
//	go(lo + v[lo - 1].first, cnt + v[lo - 1].second);
//	chk[lo] = 0;
//	go(lo + 1, cnt);
//}
//
//int main(void) {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		v.push_back({ a, b });
//	}
//	go(1, 0);
//	printf("%d\n", ans);
//	return 0;
//}
