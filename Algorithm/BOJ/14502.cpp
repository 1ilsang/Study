//
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, ans, walls;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int area[9][9];
int chk[9][9];
int visit[9][9];
queue<pair<int, int>> q;
vector<pair<int, int>> v2;

int bfs(int r, int c) {
	int ret = 1;
	q.push({ r,c });
	visit[r][c] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m && area[nr][nc] == 0 && chk[nr][nc] == 0 && visit[nr][nc] == 0) {
				visit[nr][nc] = 1;
				ret++;
				q.push({ nr,nc });
			}
		}
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
			if (area[i][j] == 2) v2.push_back({ i,j });
			else if (area[i][j] == 1) walls++;
		}
	}
	// 3개를 세움.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 1 || area[i][j] != 0) continue;
			chk[i][j] = 1;
			for (int p = i; p < n; p++) {
				for (int q = 0; q < m; q++) {
					if (chk[p][q] == 1 || area[p][q] != 0) continue;
					chk[p][q] = 1;
					for (int v = p; v < n; v++) {
						for (int w = 0; w < m; w++) {
							if (chk[v][w] == 1 || area[v][w] != 0) continue;
							chk[v][w] = 1;
							// 2를 확산해봄.
							int ret = 0;
							for (int z = 0; z < v2.size(); z++) {
								ret += bfs(v2[z].first, v2[z].second);
							}
							// 0 의 개수 체크.
							ret += walls + 3;
							// ans 값 갱신.
							ret = n*m - ret;
							if (ans < ret) ans = ret;
							memset(visit, 0, sizeof(visit));
							chk[v][w] = 0;
						}
					}
					chk[p][q] = 0;
				}
			}
			chk[i][j] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
