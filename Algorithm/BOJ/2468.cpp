//https://www.acmicpc.net/problem/2468
//http://1ilsang.blog.me/221330675430

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, maxH;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int check[101][101];
int area[101][101];

void dfs(int r, int c) {
	check[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (0 <= nr && 0 <= nc && nc < n && nr < n && area[nr][nc] > maxH && check[nr][nc] == 0) {
			dfs(nr, nc);
		}
	}
}
int main(void) {
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
			if (maxH < area[i][j]) maxH = area[i][j];
		}
	}
	while (maxH--) {
		int tmpAns = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] > maxH && check[i][j] == 0) {
					dfs(i, j);
					tmpAns++;
				}
			}
		}
		if (ans < tmpAns) ans = tmpAns;
		memset(check, 0, sizeof(check));
	}
	printf("%d\n", ans);
	return 0;
}
