//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&
//

#include <cstdio>
#include <algorithm>
using namespace std;

int area[14][21];
int tmpArea[14][21];
int pKey[14];
int d, w, k;
int ans;

bool pass(void) {
	for (int i = 0; i < w; i++) {
		bool chk1 = false;
		for (int j = 0; j <= d - k; j++) {
			bool chk2 = false;
			for (int z = j + 1; z < j + k; z++) {
				if (tmpArea[j][i] != tmpArea[z][i]) {
					chk2 = true;
					break;
				}
			}
			if (chk2 == false) {
				chk1 = true;
				break;
			}
		}
		if (chk1 == false) {
			return false;
		}
	}
	return true;
}

void go(int r, int pCnt) {
	if (pCnt >= ans) return;
	if (r == d) {
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				tmpArea[i][j] = area[i][j];
			}
		}
		for (int i = 0; i < d; i++) {
			if (pKey[i] != -1) {
				for (int j = 0; j < w; j++) {
					tmpArea[i][j] = pKey[i];
				}
			}
		}
		if (pass()) ans = min(ans, pCnt);
	}
	if (r >= d) return;
	pKey[r] = -1;
	go(r + 1, pCnt);
	pKey[r] = 0;
	go(r + 1, pCnt + 1);
	pKey[r] = 1;
	go(r + 1, pCnt + 1);
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		scanf("%d %d %d", &d, &w, &k);
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &area[i][j]);
			}
		}
		ans = d;
		go(0, 0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
