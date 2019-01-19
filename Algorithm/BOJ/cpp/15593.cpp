//https://www.acmicpc.net/problem/15593
//http://1ilsang.blog.me/221399974966

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<pair<int, int>>v;
	int chk[1001];
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a, b - 1 });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < v.size(); j++) {
			if (i == j) continue;
			for (int z = v[j].first; z <= v[j].second; z++) {
				if (chk[z] == 0) chk[z] = 1, tmp++;
			}
		}
		if (ans < tmp) ans = tmp;
		memset(chk, 0, sizeof(chk));
	}
	printf("%d\n", ans);
	return 0;
}
