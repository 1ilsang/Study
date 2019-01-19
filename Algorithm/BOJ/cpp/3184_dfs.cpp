//https://www.acmicpc.net/problem/3184
//http://1ilsang.blog.me/221317535014

#include <stdio.h>

char mapFence[251][251];
int check[251][251];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int wolf, goat, n, m;

void go(int row, int col) {
	check[row][col] = 1;
	if (mapFence[row][col] == 'v') {
		wolf++;
	}
	else if (mapFence[row][col] == 'o') {
		goat++;
	}
	for (int i = 0; i < 4; i++) {
		int nextRow = row + dr[i];
		int nextCol = col + dc[i];
		if (0<nextRow && 0 < nextCol && nextRow < n && nextCol < m && check[nextRow][nextCol] == 0 
			&& mapFence[nextRow][nextCol] != '#') {
			go(nextRow, nextCol);
		}
	}
}

int main(void) {
	int ansGoat = 0, ansWolf = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &mapFence[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && mapFence[i][j] != '#') {
				go(i, j);
				if (goat > wolf) {
					ansGoat += goat;
				}
				else {
					ansWolf += wolf;
				}
				goat = 0;
				wolf = 0;
			}
		}
	}
	printf("%d %d\n", ansGoat, ansWolf);
	return 0;
}
