//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq&categoryId=AV5PuPq6AaQDFAUq&categoryType=CODE

#include <stdio.h>
#include <string.h>

int room[51][51];
int check[51][51];
int dr[4] = { 0, 1 , 0, -1};
int dc[4] = { 1, 0, -1, 0 };
int ans, n;

void go(int r, int c, int l, int d) {
	if (l == 1) {
		ans++;
	}
	if (l == 0) {
		ans--;
		return;
	}
	int nextR = r + dr[d];
	int nextC = c + dc[d];
	if (nextR < n && nextC < n && room[nextR][nextC] == 1)
		go(nextR, nextC, l - 1, d);
}

int main(void) {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		int length;
		scanf("%d %d", &n, &length);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &room[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int d = 0; d < 2; d++) {
					int prevR = i - dr[d];
					int prevC = j - dc[d];
					if ( room[i][j] == 0 || (prevR >-1 && prevC >-1 && room[prevR][prevC] == 1)) continue;
					go(i, j, length, d);
					memset(check, 0, sizeof(check));
				}
			}
		}
		printf("#%d %d\n", cnt++, ans);
		memset(room, 0, sizeof(room));
		ans = 0;
	}
	return 0;
}