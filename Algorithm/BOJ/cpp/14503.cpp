//https://www.acmicpc.net/problem/14503
//http://1ilsang.blog.me/221355127082

#include <stdio.h>
#include <stdlib.h>

// 북동남서
int dr[4] = { -1, 0,1,0 };
int dc[4] = { 0,1,0,-1 };
int ndg[4] = { 2, 3, 0, 1 };
int area[51][51];
int chk[51][51];
int n, m;
int ans;

// 0: 북 1: 동 2: 남 3: 서
void dfs(int r, int c, int d) {
	int ndh;
	int nd = ndg[d];
	if (d == 0) ndh = 3;
	else ndh = d - 1;
	if (chk[r][c] == 0) {
		chk[r][c] = 1;
		ans++;
	}
	for (int i = ndh + 4; i >= ndh; i--) {
		int nr = r + dr[i % 4];
		int nc = c + dc[i % 4];
		if (chk[nr][nc] == 0 && area[nr][nc] == 0 && nr >= 0 && nc >= 0 && nr < n && nc < m) {
			dfs(nr, nc, i % 4);
		}
	}
	if (area[r + dr[nd]][c + dc[nd]] == 1) {
		printf("%d\n", ans);
		exit(0);
	}
	else {
		dfs(r + dr[(d + 2) % 4], c + dc[(d + 2) % 4], d);
	}
}

int main(void) {
	int sr, sc, d;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &sr, &sc, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	dfs(sr, sc, d);
	printf("%d\n", ans);
	return 0;
}
