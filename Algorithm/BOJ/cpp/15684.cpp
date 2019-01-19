//https://www.acmicpc.net/problem/15684
//http://1ilsang.blog.me/221351638700

#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, h;
int area[32][12];

bool chkAns() {
	for (int i = 1; i < n; i++) {
		int c = i;
		for (int j = 1; j <= h; j++) {
			if (area[j][c] == 1) c++;
			else if (area[j][c - 1] == 1) c--;
		}
		if (c != i) return false;
	}
	return true;
}

bool go(int r, int cnt, int mCnt) {
	if (cnt == mCnt) return chkAns();
	bool ret = false;
	for (int i = r; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (area[i][j] == 0 && area[i][j - 1] == 0 && area[i][j + 1] == 0) {
				area[i][j] = 1;
				ret = max(ret, go(i, cnt + 1, mCnt));
				area[i][j] = 0;
			}
		}
	}
	return ret;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		area[a][b] = 1;
	}
	int ans = 999;
	for (int i = 0; i < 4; i++) {
		if (go(1, 0, i)) {
			ans = i;
			break;
		}
	}
	ans == 999 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}
