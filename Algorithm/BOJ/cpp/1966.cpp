//https://www.acmicpc.net/problem/1966
//http://1ilsang.blog.me/221327388923

#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	while (tcase--) {
		int n, m, k = 0, ans = 0;
		vector<int> v;
		queue<pair<int, int>> q;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
			if (i == m) {
				q.push(make_pair(num, 1));
			}
			else {
				q.push(make_pair(num, 0));
			}
		}
		sort(v.begin(), v.end(), greater<int>());
		while (!q.empty()) {
			int nowNum = q.front().first;
			int nowCheck = q.front().second;
			q.pop();
			if (v[k] == nowNum) {
				k++;
				ans++;
				if (nowCheck == 1) {
					break;
				}
			}
			else {
				q.push(make_pair(nowNum, nowCheck));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
