//https://www.acmicpc.net/problem/14891
//

#include <cstdio>
#include <cmath>
#include <cstring>

int area[4][8];
int chk[4];

void moved(int n, int d) {
	int front = area[n][0];
	int end = area[n][7];
	if (d == -1) {
		for (int i = 0; i < 7; i++) {
			area[n][i] = area[n][i + 1];
			if (i == 6) area[n][7] = front;
		}
	}
	else {
		for (int i = 7; i > 0; i--) {
			area[n][i] = area[n][i - 1];
			if (i == 1) area[n][0] = end;
		}
	}
}

void go(int n, int d) {
	if (n < 0 || n > 4 || chk[n]) return;
	chk[n] = 1;

	if (n == 0) {
		if (area[n][2] == area[n + 1][6]) {
			moved(n, d);
			return;
		}
		else {
			moved(n, d);
			go(n + 1, d * -1);
		}
	}
	else if (n == 1 || n == 2) {
		if (area[n][2] == area[n + 1][6] && area[n][6] == area[n - 1][2]) {
			moved(n, d);
			return;
		}
		else if(area[n][2] == area[n+1][6] && area[n][6] != area[n - 1][2]){
			moved(n, d);
			go(n - 1, d*-1);
			return;
		}
		else if (area[n][2] != area[n + 1][6] && area[n][6] == area[n - 1][2]) {
			moved(n, d);
			 go(n + 1, d * -1);
			return;
		}
		else if (area[n][2] != area[n + 1][6] && area[n][6] != area[n - 1][2]) {
			moved(n, d);
			go(n + 1, d * -1);
			go(n - 1, d * -1);
			return;
		}
	}
	else if (n == 3) {
		if (area[n][6] == area[n - 1][2]) {
			moved(n, d);
			return;
		}
		else {
			moved(n, d);
			go(n - 1, d * -1);
		}
	}
}

int main(void) {
	int n;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &area[i][j]);
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, d;
		scanf("%d %d", &a, &d);
		go(a - 1, d);
		memset(chk, 0, sizeof(chk));
	}
	for (int i = 0; i < 4; i++) {
		if (area[i][0] == 1) {
			ans += pow(2, i) * 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}
