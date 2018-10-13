//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int area[105][105];
int block[6][4] = {
	{},
	{2,0,3,1},
	{2,3,1,0},
	{1,3,0,2},
	{3,2,0,1},
	{2,3,0,1}
};
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
pair<int, int> warm[2][15];
int tcase, sr, sc, sp;

int go(int r, int c, int d) {
	if (sr == r && sc == c && sp == 1) return 0;
	sp = 1;
	int ret = 0;
	int nr = r + dr[d], nc = c + dc[d];
	int num = area[nr][nc];
	if (num == -1) ret = 0;
	else if (num == 0) ret = go(nr, nc, d);
	else if (0 < num && num < 6) ret = go(nr, nc, block[num][d]) + 1;
	else {
		if (warm[0][num].first == nr && warm[0][num].second == nc)
			ret = go(warm[1][num].first, warm[1][num].second, d);
		else ret = go(warm[0][num].first, warm[0][num].second, d);
	}
	return ret;
}

int main(void) {
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		memset(warm, -1, sizeof(warm));
		int n, num;
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++) {
				if (i == 0 || j == 0 || i == n + 1 || j == n + 1) area[i][j] = 5;
				else {
					scanf("%d", &num);
					area[i][j] = num;
					if (5 < num) {
						if (warm[0][num].first == -1) warm[0][num] = { i,j };
						else warm[1][num] = { i,j };
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (area[i][j] == 0) {
					sr = i, sc = j;
					for (int d = 0; d < 4; d++)	sp = 0, ans = max(ans, go(i, j, d));
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}
	return 0;
}
