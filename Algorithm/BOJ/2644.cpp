//https://www.acmicpc.net/problem/2644
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>v;
queue<pair<int, int>>q;
int n, t1, t2, ans;
int check[101];

void bfs(int now) {
	check[now] = 1;
	q.push({ now, 0 });
	while (!q.empty()) {
		int now = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (now == t2) {
			ans = depth;
			break;
		}
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push({ next, depth + 1 });
			}
		}
	}
}

int main(void) {
	int m;
	scanf("%d", &n);
	v.resize(n + 1);
	scanf("%d %d", &t1, &t2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, w;
		scanf("%d %d", &u, &w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	bfs(t1);
	ans == 0 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}
