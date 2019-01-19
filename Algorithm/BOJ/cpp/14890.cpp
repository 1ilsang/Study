//https://www.acmicpc.net/problem/14890
//http://1ilsang.blog.me/221353974460

#include <cstdio>
#include <cstring>

int area[101][101];
int chk[101][101];
int n, L;
int ans;

int main(void) {
	scanf("%d %d", &n, &L);
	L -= 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
		}
	}

	// row
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (area[i][j] != area[i][j + 1]) {
				if (area[i][j] + 2 <= area[i][j + 1] || area[i][j] >= area[i][j + 1] + 2) {
					break;
				}
				if (area[i][j] < area[i][j + 1]) {
					int flag = 0;
					if (j - L < 0) break;
					for (int z = 0; z <= L; z++) {
						if (chk[i][j - z] == 1) {
							flag = 1;
							break;
						}
					}
					for (int z = 0; z < L; z++) {
						if (area[i][j - z] != area[i][j - z - 1]) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) break;
				}
				else {
					int flag = 0;
					if (j + L + 1 >= n) break;
					for (int z = 0; z < L; z++) {
						if (area[i][j + z + 1] != area[i][j + z + 2]) flag = 1;
						chk[i][j + z + 1] = 1;
						chk[i][j + z + 2] = 1;
					}
					if (flag == 1) break;
					if (area[i][j + L + 1] < area[i][j + L + 2]) break;
				}
			}

			if (j == n - 2) {
				ans++;
			}
		}
	}
	memset(chk, 0, sizeof(chk));

	// col
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (area[i][j] != area[i + 1][j]) {
				if (area[i][j] + 2 <= area[i + 1][j] || area[i][j] >= area[i + 1][j] + 2) {
					break;
				}
				if (area[i][j] < area[i + 1][j]) {
					int flag = 0;
					if (i - L < 0) break;
					for (int z = 0; z <= L; z++) {
						if (chk[i - z][j] == 1) {
							flag = 1;
							break;
						}
					}
					for (int z = 0; z < L; z++) {
						if (area[i - z][j] != area[i - z - 1][j]) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) break;
				}
				else {
					int flag = 0;
					if (i + L + 1 >= n) break;
					for (int z = 0; z < L; z++) {
						if (area[i + z + 1][j] != area[i + z + 2][j]) flag = 1;
						chk[i + z + 1][j] = 1;
						chk[i + z + 2][j] = 1;
					}
					if (flag == 1) break;
					if (area[i + L + 1][j] < area[i + L + 2][j]) break;
				}
			}

			if (i == n - 2) {
				ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
