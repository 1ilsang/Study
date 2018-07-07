//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&categoryId=AV5PzOCKAigDFAUq&categoryType=CODE

#include <stdio.h>
#include <algorithm>
using namespace std;

int flyMap[16][16];
int n, m, ans;

int go(int row, int col) {
	int ret = 0;
	for (int i = row; i < row + m; i++) {
		if (i < n) {
			for (int j = col; j < col + m; j++) {
				if(j < n) ret += flyMap[i][j];
			}
		}
	}
	return ret;
}

int main(void) {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &flyMap[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(go(i, j), ans);
			}
		}
		printf("#%d %d\n", cnt++, ans);
		ans = 0;
	}
	return 0;
}
