//https://www.acmicpc.net/problem/14499
//

#include <cstdio>

int n, m, x, y;
int dr[5] = { 0,0,0,-1,1 };
int dc[5] = { 0,1,-1,0,0 };
int area[21][21];
int dice[7];
int ans;
int now = 1;
int left = 4;
int up = 2;

void go(int cmd) {
	int nr = x + dr[cmd];
	int nc = y + dc[cmd];
	if (nr < 0 || nc < 0 || nr >= n || nc >= m) return;
	int tmp = now;
	if (area[x][y] == 0) {
		area[x][y] = dice[7 - now];
	}
	else{
		dice[7 - now] = area[x][y];
		area[x][y] = 0;
	}
	x = nr;
	y = nc;
	if (cmd == 1) {
		now = left;
		left = 7 - tmp;
	}
	else if (cmd == 2) {
		now = 7 - left;
		left = tmp;
	}
	else if (cmd == 3) {
		now = 7 - up;
		up = tmp;
	}
	else if (cmd == 4) {
		now = up;
		up = 7 - tmp;
	}
	ans = dice[now];
	printf("%d\n", ans);
}

int main(void) {
	int k;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int cmd;
		scanf("%d", &cmd);
		go(cmd);
	}
	return 0;
}
