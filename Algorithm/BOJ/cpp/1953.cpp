//https://www.acmicpc.net/problem/1953
//http://1ilsang.blog.me/221319603506

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(1000), ans(4);
int check[101];

void dfs(int now, int oddEven) {
	if (check[now] == 1) return;
	check[now] = 1;
	ans[oddEven].push_back(now);
	for (int i = 0; i < v[now].size(); i++) {
		dfs(v[now][i], 3 - oddEven);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmpN;
		scanf("%d", &tmpN);
		for (int j = 0; j < tmpN; j++){
			int tmp;
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
	}
	sort(ans[1].begin(), ans[1].end());
	sort(ans[2].begin(), ans[2].end());
	printf("%d\n", ans[1].size());
	for (int i = 0; i < ans[1].size(); i++) {
		printf("%d ", ans[1][i]);
	}
	printf("\n%d\n", ans[2].size());
	for (int i = 0; i < ans[2].size(); i++) {
		printf("%d ", ans[2][i]);
	}puts("");
	return 0;
}
