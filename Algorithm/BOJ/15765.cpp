//https://www.acmicpc.net/problem/15765
//http://1ilsang.blog.me/221397032852

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

vector<vector<int>> v;
map<string, int> m1;
map<int, string> m2;
int check[505], parent[505], degree[505], dep[505];
int d, h;

int go2(int now, int des) {
	if (check[now]) return 0;
	check[now] = 1;
	if (now == des) return 1;
	for (int i = 0; i < v[now].size(); i++) {
		h--, d++;
		if (go2(v[now][i], des)) return 1;
		h++, d--;
	}
	h++;
	if (go2(parent[now], des)) return 1;
	h--;
	return 0;
}

void go(int n, int h) {
	dep[n] = h;
	for (int i = 0; i < v[n].size(); i++) go(v[n][i], h + 1);
}

int main(void) {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	int cnt = 0;
	v.resize(500);
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (m1.count(a) == 0) {
			m1[a] = cnt;
			m2[cnt++] = a;
		}
		if (m1.count(b) == 0) {
			m1[b] = cnt;
			m2[cnt++] = b;
		}
		parent[m1[b]] = m1[a];
		v[m1[a]].push_back(m1[b]);
		degree[m1[b]]++;
	}
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0) go(i, 0);
	}
	int a = m1[s1], b = m1[s2];
	if (dep[a] < dep[b]) swap(a, b);
	if (parent[a] != -1 && parent[a] == parent[b]) {
		printf("SIBLINGS");
		return 0;
	}
	else if (go2(a, b)) {
		if (d == 0) {
			printf("%s is the ", m2[b].c_str());
			for (int i = 0; i < h - 2; i++) printf("great-");
			if (h >= 2) printf("grand-");
			printf("mother of %s", m2[a].c_str());
		}
		else if (d == 1) {
			printf("%s is the ", m2[b].c_str());
			for (int i = 0; i < h - 1; i++) printf("great-");
			printf("aunt of %s", m2[a].c_str());
		}
		else {
			printf("COUSINS");
		}
	}
	else {
		printf("NOT RELATED");
	}
	return 0;
}
