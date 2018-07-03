//https://www.acmicpc.net/problem/2573

#include <cstdio>
#include <string.h>
int map[301][301];
int map2[301][301];
int check[301][301];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int ans, n, m, iceFlag, startX, startY;

int find2mountain(int nowRow, int nowCol) {
	int ret = 1;
	check[nowRow][nowCol] = 1;
	//printf("find %d %d\n", nowRow, nowCol);
	for (int i = 0; i < 4; i++) {
		int nextRow = nowRow + dr[i];
		int nextCol = nowCol + dc[i];
		if (nextRow < n && nextCol < m && check[nextRow][nextCol] == 0
			&& map[nextRow][nextCol] > 0) {
			ret += find2mountain(nextRow, nextCol);
		}
	}
	return ret;
}

int mapSumAndCheckIce() {
	int iceCnt = 0, flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] += map2[i][j];
			if (map[i][j] > 0 && flag > 0) {
				flag = 0;
				startX = i;
				startY = j;
			}
			if (map[i][j] > 0) {
				iceCnt++;
			}
			if (map[i][j] < 0) {
				map[i][j] = 0;
			}
		}
	}
	return iceCnt;
}

void yearAfter(int nowRow, int nowCol) {
	check[nowRow][nowCol] = 1;
	for (int i = 0; i < 4; i++) {
		int nextRow = nowRow + dr[i];
		int nextCol = nowCol + dc[i];
		if (nextRow < n && nextCol < m &&
			map[nextRow][nextCol] == 0 && map[nowRow][nowCol] > 0) {
			map2[nowRow][nowCol]--;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nextRow = nowRow + dr[i];
		int nextCol = nowCol + dc[i];
		if (nextRow < n && nextCol < m && check[nextRow][nextCol] == 0
			&& map[nextRow][nextCol] > 0) {
			yearAfter(nextRow, nextCol);
		}
	}
}

int main(void) {
	int flag = 1, iceCnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (flag == 1 && map[i][j] > 0) {
				flag = 0;
				startX = i;
				startY = j;
			}
			if (map[i][j] > 0) {
				iceCnt++;
			}
		}
	}

	int findMountainFlag, isTrue = 1, ans = 0;

	do {
		findMountainFlag = find2mountain(startX, startY);
		memset(check, 0, sizeof(check));
		//printf("findMountainFlag = %d, iceCnt = %d\n", findMountainFlag, iceCnt);
		if (iceCnt == 0) {
			ans = 0;
			isTrue = 0;
		}
		else if (findMountainFlag == iceCnt) {
			yearAfter(startX, startY);
			memset(check, 0, sizeof(check));

			iceCnt = mapSumAndCheckIce();

			/*puts("");
			for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
			}puts("");
			}*/
			memset(map2, 0, sizeof(map2));
			ans++;
		}
		else {
			isTrue = 0;
		}
	} while (isTrue);

	printf("%d\n", ans);
	return 0;
}