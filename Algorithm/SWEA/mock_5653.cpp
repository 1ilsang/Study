//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo
//

#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Pair;

int tcase, n, m, k;
int cells[700][700];
int chk[700][700];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
const int MOD = 300;

int main(void) {
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = MOD; i < n + MOD; i++) {
			for (int j = MOD; j < m + MOD; j++) {
				scanf("%d", &cells[i][j]);
				if (cells[i][j] > 0) {
					chk[i][j] = 1;
					pq.push({ {cells[i][j], -cells[i][j]}, {i,j} });
				}
			}
		}
		for (int time = 1; time < k; time++) {
			while (!pq.empty() && pq.top().first.first == time) {
				int r = pq.top().second.first;
				int c = pq.top().second.second;
				int v = -pq.top().first.second;
				pq.pop();
				if (v == 5000) continue;
				pq.push({ {time + v - 1, -5000}, {-1,-1} });
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (chk[nr][nc] == 0) {
						chk[nr][nc] = 1;
						pq.push({ {time + v + 1, -v}, {nr, nc} });
					}
				}
			}
		}
		printf("#%d %d\n", t, pq.size());
		memset(chk, 0, sizeof(chk));
		memset(cells, 0, sizeof(cells));
	}
	return 0;
}
