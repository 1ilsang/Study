//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
//http://1ilsang.blog.me/221375526869

#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int r, c, p;
};

const int C = 15;
queue<Node> q;
int tcase, n, w, h;
int chk[15][C];
int area[15][C];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int getAreaValue(int area[][C]) {
	int ret = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (area[i][j] > 0) ret++;
		}
	}
	return ret;
}

void findFirstPoint(int area[][C], int c) {
	for (int i = 0; i < h; i++) {
		if (area[i][c] > 0) {
			q.push({ i,c,area[i][c] });
			chk[i][c] = 1;
			area[i][c] = 0;
			break;
		}
	}
}

void gravity(int area[][C]) {
	for (int i = 0; i < w; i++) {
		stack<int> stk;
		for (int j = 0; j < h; j++) {
			if (area[j][i] > 0) stk.push(area[j][i]);
		}
		for (int j = h - 1; j >= 0; j--) {
			if (!stk.empty()) area[j][i] = stk.top(), stk.pop();
			else area[j][i] = 0;
		}
	}
}

void dfs(int r, int c, int p, int d, int area[][C]) {
	int nr = r + dr[d];
	int nc = c + dc[d];
	if (p - 1 > 0 && nr >= 0 && nc >= 0 && nr < h && nc < w) {
		if (chk[nr][nc] == 0) {
			chk[nr][nc] = 1;
			q.push({ nr,nc,area[nr][nc] });
		}
		dfs(nr, nc, p - 1, d, area);
	}
}

int go(int cnt) {
	if (cnt == 0) return getAreaValue(area);
	int ret = 9999999;
	int tmpArea[15][C];
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) tmpArea[i][j] = area[i][j];
	for (int c = 0; c < w; c++) {
		findFirstPoint(area, c);
		//fire - BFS
		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int p = q.front().p;
			q.pop();
			area[r][c] = 0;
			for (int i = 0; i < 4; i++) 	dfs(r, c, p, i, area);
		}
		gravity(area);
		memset(chk, 0, sizeof(chk));
		ret = min(ret, go(cnt - 1));
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) area[i][j] = tmpArea[i][j];
	}
	return ret;
}

int main(void) {
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		scanf("%d %d %d", &n, &w, &h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &area[i][j]);
			}
		}
		printf("#%d %d\n", t, go(n));
	}
	return 0;
}
