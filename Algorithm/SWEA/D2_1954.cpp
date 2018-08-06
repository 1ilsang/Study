//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PobmqAPoDFAUq&categoryId=AV5PobmqAPoDFAUq&categoryType=CODE
//http://1ilsang.blog.me/221333483954

#include <cstdio>
#include <cstring>
int check[11][11];
int ans[11][11];
int dc[4] = { 1,0,-1,0 };
int dr[4] = { 0,1,0,-1 };
int k = 1;
int md = 0;
int n;
void go(int nowR, int nowC) {
	check[nowR][nowC] = 1;
	ans[nowR][nowC] = k++;
	int nr = nowR + dr[md];
	int nc = nowC + dc[md];
	if (nc == 0 || nr > n || nc > n || check[nr][nc] == 1) {
		md = (md + 1) % 4;
		nr = nowR + dr[md];
		nc = nowC + dc[md];
	}
	//printf(" %d %d %d\n", nowR, nowC, md);
	if(0<nr && 0 < nc && nr <= n && nc <= n && check[nr][nc] ==0)
	go(nr, nc);
}
int main(void) {
	int tcase;
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		scanf("%d", &n);
		go(1, 1);
		printf("#%d\n", t);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", ans[i][j]);
			}puts("");
		}
		k = 1;
		md = 0;
		memset(check, 0, sizeof(check));
	}
	return 0;
}
