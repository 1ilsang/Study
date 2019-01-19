//https://www.acmicpc.net/problem/2178
//http://1ilsang.blog.me/221329606386

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int room[101][101];
int check[101][101];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
queue<pair<int, pair<int, int>>> q;

void bfs(int r, int c) {
	check[r][c] = 1;
	q.push({ 1, { r,c } });
	while (!q.empty()) {
		int nowRow = q.front().second.first;
		int nowCol = q.front().second.second;
		int nowAns = q.front().first;
		q.pop();
		if (nowRow + 1 == n && nowCol + 1 == m) {
			printf("%d\n", nowAns);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nr = nowRow + dr[i];
			int nc = nowCol + dc[i];
			if (0 <= nr && 0 <= nc&&nr < n&&nc < m
				&& room[nr][nc] == 1 && check[nr][nc] == 0) {
				check[nr][nc] = 1;
				q.push({ nowAns + 1, {nr,nc} });
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &room[i][j]);
		}
	}
	bfs(0, 0);
	return 0;
}
