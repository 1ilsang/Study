//https://www.acmicpc.net/problem/1987
//http://1ilsang.blog.me/221332176026

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int r, c;
int board[21][21];
int checkAlpa[27];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int go(int nowR, int nowC, int lo) {
	int ret = 0;
	checkAlpa[board[nowR][nowC]] = 1;
	//printf(" %d %d %C %d %d\n", nowR, nowC, board[nowR][nowC] + 'A', lo, ans);
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < r && nc < c &&
			 checkAlpa[board[nr][nc]] == 0) {
			ret = max(ret, go(nr, nc, lo + 1));
		}
	}
	//puts("");
	checkAlpa[board[nowR][nowC]] = 0;
	return ret + 1;
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			board[i][j] = tmp[j] - 'A';
		}
	}
	printf("%d\n", go(0, 0, 1));
	return 0;
}
