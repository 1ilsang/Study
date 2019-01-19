//https://www.acmicpc.net/problem/13265
//http://1ilsang.blog.me/221321889116

#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

vector<vector<int>> v(1002);
queue<pair<int, int>> q;
pair<int, int> p;
int check[1002];
int checkColor[1002];
int flag;

void bfs(int now, int oddEven) {
	check[now] = 1;
	q.push(make_pair(now, oddEven));
	checkColor[now] = oddEven;
	while (!q.empty()) {
		p = q.front();
		check[p.first] = 1;
		q.pop();
		//printf(" A %d %d %d\n", p.first, p.second, checkColor[p.first]);
		for (int i = 0; i < v[p.first].size(); i++) {
			int next = v[p.first][i];
			if (check[next] == 0) {
				q.push(make_pair(next, 3 - p.second));
				check[next] = 1;
				checkColor[next] = 3 - p.second;
				//printf("  b %d %d %d\n", next, 3-p.second, checkColor[next]);
			}
			else if (check[next] == 1 && checkColor[next] == p.second) {
				//printf("   cc %d %d %d\n", i, next, checkColor[next]);
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, ans = 0;
		v.clear();
		v.resize(n + 1);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int node, node2;
			scanf("%d %d", &node, &node2);
			v[node].push_back(node2);
			v[node2].push_back(node);
		}
		for (int i = 1; i <= n; i++) {
			if(check[i] == 0 && flag == 0)
			bfs(i, i % 2 + 1);
		}
		if (flag == 1) printf("impossible\n");
		else printf("possible\n");
		memset(check, 0, sizeof(check));
		while (!q.empty()) q.pop();
		flag = 0;
	}
	return 0;
}
