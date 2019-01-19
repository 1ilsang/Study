//https://www.acmicpc.net/problem/15686
//http://1ilsang.blog.me/221349989107

//Sample 1 - 2^n Backtracking
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int area[51][51];
int chk[14];
vector<pair<int, int>> v, w;

int go(int lo, int cnt) {
	int ret = 9999999;
	if (lo == v.size()) {
		if (0 < cnt && cnt <= m) {
			int ret = 0;
			vector<int> ans;
			ans.resize(n * 2);
			fill(ans.begin(), ans.end(), 9999999);
			for (int i = 0; i < w.size(); i++) {
				int wr = w[i].first;
				int wc = w[i].second;
				for (int j = 0; j < v.size(); j++) {
					if (chk[j] == 0) continue;
					int vr = v[j].first;
					int vc = v[j].second;
					int dst = abs(vr - wr) + abs(vc - wc);
					if (ans[i] > dst) ans[i] = dst;
				}
			}
			for (int i = 0; i < ans.size(); i++) if (ans[i] != 9999999) ret += ans[i];
			return ret;
		}
		else return ret;
	}
	chk[lo] = 1;
	ret = min(ret, go(lo + 1, cnt + 1));
	chk[lo] = 0;
	ret = min(ret, go(lo + 1, cnt));
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			area[i][j] = num;
			if (num == 2) v.push_back({ i,j });
			else if (num == 1) w.push_back({ i,j });
		}
	}
	if (v.size() == 0) printf("0\n");
	else printf("%d\n", go(0, 0));
	return 0;
}



// Sample2 - DFS
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#define INF 987654321
//using namespace std;
//
//vector<pair<int, int>> h, c;
//int visit[14];
//int ans = INF;
//int n, m;
//
//int getDistance() {
//	int ret = 0;
//	for (int i = 0; i < h.size(); i++) {
//		int minDist = INF;
//		for (int j = 0; j < c.size(); j++) {
//			if (visit[j] == 1) {
//				int rd = h[i].first - c[j].first;
//				int cd = h[i].second - c[j].second;
//				rd = rd < 0 ? rd * -1 : rd;
//				cd = cd < 0 ? cd * -1 : cd;
//				int dst = rd + cd;
//				minDist = min(dst, minDist);
//			}
//		}
//		ret += minDist;
//	}
//	return ret;
//}
//
//void dfs(int lo, int cnt) {
//	visit[lo] = 1;
//
//	if (cnt == m) {
//		ans = min(ans, getDistance());
//	}
//	else {
//		for (int i = lo + 1; i < c.size(); i++) {
//			dfs(i, cnt + 1);
//		}
//	}
//
//	visit[lo] = 0;
//}
//
//int main(void) {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &tmp);
//			if (tmp == 1) h.push_back({ i, j });
//			else if (tmp == 2) c.push_back({ i, j });
//		}
//	}
//	for (int i = 0; i < c.size(); i++) {
//		dfs(i, 1);
//	}
//	printf("%d\n", ans);
//	return 0;
//}
