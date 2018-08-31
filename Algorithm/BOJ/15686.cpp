//https://www.acmicpc.net/problem/15686
//http://1ilsang.blog.me/221349989107

#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> h, c;
int visit[14];
int ans = INF;
int n, m;

int getDistance() {
	int ret = 0;
	for (int i = 0; i < h.size(); i++) {
		int minDist = INF;
		for (int j = 0; j < c.size(); j++) {
			if (visit[j] == 1) {
				int rd = h[i].first - c[j].first;
				int cd = h[i].second - c[j].second;
				rd = rd < 0 ? rd * -1 : rd;
				cd = cd < 0 ? cd * -1 : cd;
				int dst = rd + cd;
				minDist = min(dst, minDist);
			}
		}
		ret += minDist;
	}
	return ret;
}

void dfs(int lo, int cnt) {
	visit[lo] = 1;

	if (cnt == m) {
		ans = min(ans, getDistance());
	}
	else {
		for (int i = lo + 1; i < c.size(); i++) {
			dfs(i, cnt + 1);
		}
	}

	visit[lo] = 0;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)	{
		int tmp;
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			if (tmp == 1) h.push_back({ i, j });
			else if (tmp == 2) c.push_back({ i, j });
		}
	}
	for (int i = 0; i < c.size(); i++) {
		dfs(i, 1);
	}
	printf("%d\n", ans);
	return 0;
}
