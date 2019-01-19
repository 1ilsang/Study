//https://www.acmicpc.net/problem/1600
//http://1ilsang.blog.me/221379416759

#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node{
	int r, c, p, cnt;
};

int k, n, m;
int area[204][204];
int chk[204][204][31];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int hdr[8] = { -2, -1,1,2, 2,1,-1,-2 };
int hdc[8] = { 1,2,2,1, -1,-2,-2,-1 };
queue<Node> q;

void go(int r, int c, int h) {
	chk[r][c][0] = 1;
	q.push({ r,c,0, 0 });
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int p = q.front().p;
		int cnt = q.front().cnt;
		q.pop();
		if (r == n - 1 && c == m - 1) {
			printf("%d\n", cnt);
			exit(0);
		}
		if (p < k) {
			for (int i = 0; i < 8; i++) {
				int nr = r + hdr[i];
				int nc = c + hdc[i];
				if (nr >= 0 && nc >= 0 && nr < n && nc < m && chk[nr][nc][p + 1] == 0 && area[nr][nc] == 0) {
					chk[nr][nc][p+ 1] = 1;
					q.push({ nr,nc,p + 1,cnt + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m && area[nr][nc] == 0 && chk[nr][nc][p] == 0) {
				chk[nr][nc][p] = 1;
				q.push({ nr,nc,p ,cnt + 1 });
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &k, &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	go(0, 0, k);
	printf("-1\n");
	return 0;
}
