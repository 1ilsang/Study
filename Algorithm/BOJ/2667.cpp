//https://www.acmicpc.net/problem/2667
//http://1ilsang.blog.me/221330651097

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int area[26][26];
int check[26][26];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int dfs(int r, int c) {
	int ret = 1;
	check[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(0<= nr && 0 <= nc && nr < n && nc < n && check[nr][nc] == 0 && area[nr][nc] == 1){
			ret += dfs(nr, nc);
		}
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &area[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] == 1 && check[i][j] == 0) {
				int tmp = dfs(i, j);
				if (tmp) {
					v.push_back(tmp);
				}
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}
