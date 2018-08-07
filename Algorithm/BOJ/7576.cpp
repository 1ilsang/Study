//https://www.acmicpc.net/problem/7576
//

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int check[1001][1001];
int board[1001][1001];
queue<pair<pair<int, int>, int>> q;
int m, n;
int ans = -1;

void bfs() {
	while (!q.empty()) {
		int nowR = q.front().first.first;
		int nowC = q.front().first.second;
		int nowN = q.front().second;
		if (nowN > ans) ans = nowN;
	//	printf(" %d %d %d\n", nowR, nowC, nowN);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = nowR + dr[i];
			int nc = nowC + dc[i];
			if (0 <= nc && 0 <= nr && nc < m && nr < n && check[nr][nc] == 0 && board[nr][nc] == 0) {
				check[nr][nc] = 1;
				q.push({ {nr,nc}, nowN + 1 });
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) {
				q.push({ { i, j }, 0 });
				check[i][j] = 1;
			}
			else if (board[i][j] == -1) {
				check[i][j] = 1;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) ans = -1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
