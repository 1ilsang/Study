//https://www.acmicpc.net/problem/16236
//http://1ilsang.blog.me/221384331252

#include <cstdio>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;

int area[21][21];
int chk[21][21];
int n, ans, docSize = 2, eatSize;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
typedef pair<int, pair<int, int>> Pair;

int main(void) {
	int strtR, strtC;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
			if (area[i][j] == 9) strtR = i, strtC = j;
		}
	}
	while (true) {
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		queue < pair<int, pair<int, int>> >q;
		q.push({ 0,{strtR, strtC} });
		while (!q.empty()) {
			int r = q.front().second.first, c = q.front().second.second, cnt = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr >= 0 && nc >= 0 && nr < n&&nc < n&&area[nr][nc] <= docSize &&chk[nr][nc] == 0) {
					chk[nr][nc] = 1;
					if (area[nr][nc] > 0 && area[nr][nc] < docSize) {
						pq.push({ cnt + 1, {nr, nc} });
					}
					q.push({ cnt + 1, {nr, nc} });
				}
			}
		}
		if (pq.empty()) break;
		area[strtR][strtC] = 0;
		strtR = pq.top().second.first;
		strtC = pq.top().second.second;
		area[strtR][strtC] = 0;
		ans += pq.top().first;
		memset(chk, 0, sizeof(chk));
		eatSize++;
		if (docSize == eatSize)docSize++, eatSize = 0;
	}
	printf("%d\n", ans);
	return 0;
}
