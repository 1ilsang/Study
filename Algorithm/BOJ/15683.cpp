//https://www.acmicpc.net/problem/15683
//http://blog.naver.com/1ilsang/221352469553

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int d, r, c;
};

int n, m, k;
int area[9][9];
int chk[9][9];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<int> v;
vector<Node> cam;

int chkBlindSpot() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0 && area[i][j] == 0) ret++;
		}
	}
	return ret;
}

void chkGo(int r, int c, int i, int d) {
	for (int nc = c + dc[(v[i] + d) % 4], nr = r + dr[(v[i] + d) % 4];
		nr >= 0 && nc >= 0 && nr < n && nc < m && area[nr][nc] != 6;
		nc += dc[(v[i] + d) % 4], nr += dr[(v[i] + d) % 4]) {
			chk[nr][nc] = 1;
	}
}

void settingCam() {
	for (int i = 0; i < cam.size(); i++) {
		int r = cam[i].r;
		int c = cam[i].c;
		if (cam[i].d == 1) {
			chkGo(r, c, i, 0);
		}
		else if (cam[i].d == 2) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 2);
		}
		else if (cam[i].d == 3) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 3);
		}
		else if (cam[i].d == 4) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 2);
			chkGo(r, c, i, 3);
		}
		else if (cam[i].d == 5) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 1);
			chkGo(r, c, i, 2);
			chkGo(r, c, i, 3);
		}
	}
}


int go(int lo) {
	if (v.size() == cam.size()) {
		memset(chk, 0, sizeof(chk));
		settingCam();
		return chkBlindSpot();
	}
	int ret = 999;
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		ret = min(ret, go(i));
		v.pop_back();
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
			if (0 < area[i][j] && area[i][j] < 6) cam.push_back({ area[i][j], i, j });
		}
	}
	printf("%d\n", go(0));
	return 0;
}
