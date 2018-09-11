//https://www.acmicpc.net/problem/3190
//http://1ilsang.blog.me/221356918219

#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int area[101][101];
int chk[101][101];
// D68-R // L76
int  sec[1000002];
int n;
queue<pair<int, int>> tail;

void go(int r, int c, int t, int d) {
	if (r < 0 || c < 0 || r >= n || c >= n || chk[r][c] == 1) {
		printf("%d\n", t);
		exit(0);
	}
	chk[r][c] = 1;
	tail.push({ r,c });
	if (area[r][c] == 0 && t > 0) {
		chk[tail.front().first][tail.front().second] = 0;
		tail.pop();
	}
	else if (area[r][c] == 1) {
		area[r][c] = 0;
	}
	if (sec[t] == 68) {
		go(r + dr[(d + 1) % 4], c + dc[(d + 1) % 4], t + 1, (d + 1) % 4);
	}
	else if (sec[t] == 76) {
		int nd;
		if (d - 1 < 0) nd = 3;
		else nd = d - 1;
		go(r + dr[nd], c + dc[nd], t + 1, nd);
	}
	else {
		go(r + dr[d], c + dc[d], t + 1, d);
	}
}

int main(void) {
	int k, s = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		area[x - 1][y - 1] = 1;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int tmp, tmp2;
		scanf("%d %C", &tmp, &tmp2);
		sec[tmp] = tmp2;
	}
	go(0, 0, 0, 0);
	return 0;
}
