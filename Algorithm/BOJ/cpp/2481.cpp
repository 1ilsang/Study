//https://www.acmicpc.net/problem/2481
//http://1ilsang.blog.me/221325103067

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

map<int, int> hm;
vector<vector<int>> v;
vector<int> parentArr;
queue<int> q;

int main(void) {
	int n, k, m;
	int tmp[31];
	scanf("%d %d", &n, &k);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int distN = 0;
		for (int j = 0; j < k; j++) {
			scanf("%1d", &tmp[j]);
		}
		for (int j = k -1; j >= 0; j--) {
			distN += tmp[j] * (1 << k - j - 1);
		}
		hm[distN] = i;
	}
	/*for (auto iter : hm) {
		cout << iter.first << " " << iter.second << '\n';
	}puts("");*/
	for (auto iter : hm) {
		for (int i = 0; i < k; i++) {
			if (hm.count(iter.first ^ (1 << i))) {
				v[iter.second].push_back(hm[iter.first ^ (1 << i)]);
				//cout << iter.second << " " << hm[(iter.first ^ (1 << i))] << '\n';
			}
		}
	}
	//phase 2.
	q.push(1);
	parentArr.resize(n + 1, -1);
	parentArr[0] = 0;
	parentArr[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (parentArr[v[now][i]] == -1) {
				parentArr[v[now][i]] = now;
				q.push(v[now][i]);
			}
		}
	}
	/*for (int i = 0; i <= n; i++) {
		printf("%d ", parentArr[i]);
	}*/
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int endPoint;
		vector<int> ans;
		scanf("%d", &endPoint);
		while (true) {
			ans.push_back(endPoint);
			endPoint = parentArr[endPoint];
			if (endPoint == -1 || endPoint == 0) break;
		}
		if (ans.back() != 1) {
			printf("-1\n");
			continue;
		}
		for (int j = ans.size() - 1; j >= 0; j--) {
			printf("%d ", ans[j]);
		}puts("");
	}
	return 0;
}
