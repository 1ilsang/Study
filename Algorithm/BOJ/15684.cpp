//https://www.acmicpc.net/problem/15684
//

#include <cstdio>

int arr[31][11];
int ans = 987654321;
int n, m, h;

bool chk() {
	for (int z = 1; z <= n; z++) {
		int cur = z;
		for (int i = 1; i <= h; i++) {
			if (arr[i][cur] == 1) {
				cur++;
			}
			else if (arr[i][cur - 1] == 1) {
				cur--;
			}
		}
		if (cur == z) continue;
		else return false;
	}
	return true;
}

void go(int r, int cnt, int mCnt) {
	if (ans != 987654321) return;
	if (cnt >= mCnt) {
		if (chk()) {
			ans = cnt;
		}
		return;
	}
	for (int i = r; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == 1 || arr[i][j - 1] == 1 || arr[i][j + 1] == 1) {
				continue;
			}
			arr[i][j] = 1;
			go(i, cnt + 1, mCnt);
			arr[i][j] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	// 사다리를 놓는 횟수
	for (int i = 0; i < 4; i++) {
		go(1, 0, i);
		if (ans != 987654321) break;
	}
	ans == 987654321 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}
