//https://www.acmicpc.net/problem/10026
//http://1ilsang.blog.me/221336474204

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int n;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int area[101][101];
int check[101][101];
int ans[5];
int now;

void dfs(int nowR, int nowC) {
	check[nowR][nowC] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < n && nc < n 
			&& check[nr][nc] == 0 && now == area[nr][nc]) {
			dfs(nr, nc);
		}
	}
}

int main(void) {
	int ansA, ansB;
	string tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if (tmp[j] == 'R') {
				area[i][j] = 1;
			}
			else if (tmp[j] == 'G') {
				area[i][j] = 2;
			}
			else if (tmp[j] == 'B') {
				area[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				now = area[i][j];
				dfs(i, j);
				ans[area[i][j]]++;
			}
		}
	}
	ansA = ans[1] + ans[2] + ans[3];
	ans[1] = ans[2] = ans[3] = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] == 2) {
				area[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				now = area[i][j];
				dfs(i, j);
				ans[area[i][j]]++;
			}
		}
	}
	ansB = ans[1] + ans[3];
	printf("%d %d\n", ansA, ansB);
	return 0;
}
