//https://www.acmicpc.net/problem/11724
//http://1ilsang.blog.me/221335769070

#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> v;
int check[1001];

void go(int now) {
	check[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if(check[next] == 0) go(next);
	}
}

int main(void) {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, w;
		scanf("%d %d", &u, &w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (check[i] == 0) {
			ans++;
			go(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
