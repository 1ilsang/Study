//https://www.acmicpc.net/problem/2583
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int check[101][101];
int area[101][101];
int m, n;

int dfs(int nowR, int nowC) {
	int ret = 1;
	check[nowR][nowC] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < m && nc < n && check[nr][nc] == 0 && area[nr][nc] == 0) {
			ret += dfs(nr, nc);
		}
	}
	return ret;
}

int main(void) {
	int k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		y1 = m - y1 - 1;
		y2 = m - y2;
		for (int u = y2; u <= y1; u++) {
			for (int w = x1; w < x2; w++) {
				area[u][w] = 1;
			}
		}
	}
	for (int u = 0; u <m; u++) {
		for (int w = 0; w < n; w++) {
			if (check[u][w] == 0 && area[u][w] == 0) {
				v.push_back(dfs(u, w));
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}puts("");
	return 0;
}
