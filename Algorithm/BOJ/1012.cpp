//https://www.acmicpc.net/problem/1012
//

#include <cstdio>
#include <cstring>

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int check[51][51];
int area[51][51];
int m, n;

void dfs(int nowR, int nowC) {
	check[nowR][nowC] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < n && nc < m && check[nr][nc] == 0 && area[nr][nc] == 1) {
			dfs(nr, nc);
		}
	}
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	while (tcase--) {
		int k, ans = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int u, w;
			scanf("%d %d", &u, &w);
			area[w][u] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] == 0 && area[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		memset(check, 0, sizeof(check));
		memset(area, 0, sizeof(area));
		printf("%d\n", ans);
	}
	return 0;
}
