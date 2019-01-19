//https://www.acmicpc.net/problem/1260
//http://1ilsang.blog.me/221331291446

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> vec;
queue<int> q;
int check[1001];

void dfs(int now) {
	check[now] = 1;
	printf("%d ", now);
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (check[next] == 0) dfs(next);
	}
}

void bfs(int now) {
	q.push(now);
	check[now] = 1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (check[next] == 0) { 
				q.push(next); 
				check[next] = 1;
			}
		}
	}
}

int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	vec.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, w;
		scanf("%d %d", &u, &w);
		vec[u].push_back(w);
		vec[w].push_back(u);
	}
	for(int i = 1; i <=n; i++)
		sort(vec[i].begin(), vec[i].end());
	/*for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			printf("%d %d\n", vec[i][j], vec[i][j]);
	}*/
	dfs(v);
	puts("");
	memset(check, 0, sizeof(check));
	bfs(v);
	return 0;
}
