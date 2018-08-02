//https://www.acmicpc.net/problem/13023
//

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v;
int check[2002];
int flag;

void dfs(int now, int d) {
	if (d == 4) {
		flag = 1;
		return;
	}
	check[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (check[next] == 0) {
			 dfs(next, d + 1);
		}
		if (flag == 1) return;
	}
	check[now] = 0;
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n);
	for (int i = 0; i < m; i++) {
		int u, w;
		scanf("%d %d", &u, &w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		if (flag == 1) break;
		memset(check, 0, sizeof(check));
	}
	flag == 0 ? printf("0\n") : printf("1\n");
	return 0;
}
