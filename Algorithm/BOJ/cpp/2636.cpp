//https://www.acmicpc.net/problem/2636
//http://1ilsang.blog.me/221333154938

#include <cstdio>
#include <cstring>

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int ch[101][101];
int check[101][101];
int board[101][101];
int r, c;

int dfs(int nowR, int nowC) {
	int ret = 1;
	check[nowR][nowC] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < r && nc < c
			&& board[nr][nc] == 1 && check[nr][nc] == 0) {
			ret += dfs(nr, nc);
		}
	}	
	return ret;
}
void dfs2(int nowR, int nowC) {
	check[nowR][nowC] = -1;
	for (int i = 0; i < 4; i++) {
		int nr = nowR + dr[i];
		int nc = nowC + dc[i];
		if (0 <= nr && 0 <= nc && nr < r && nc < c) {
			if (board[nr][nc] == 1) {
				ch[nr][nc] = 1;
			}
			if (board[nr][nc] == 0 && check[nr][nc] == 0)
				dfs2(nr, nc);
		}
	}
}
int main(void) {
	int k = 1;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	while (k++) {
		int che1 = 0, che2 = 0;
		dfs2(0, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if(board[i][j] == 1 && check[i][j] == 0)
					che1 += dfs(i, j);
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == ch[i][j] && ch[i][j] == 1) {
					che2++;
					board[i][j] = 0;
				}
			}
		}
		if (che1 == che2) {
			printf("%d\n%d\n", k - 1, che1);
			break;
		}
		memset(ch, 0, sizeof(ch));
		memset(check, 0, sizeof(check));
	}
	return 0;
}
