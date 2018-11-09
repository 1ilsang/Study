//https://www.acmicpc.net/problem/15763
//http://1ilsang.blog.me/221395267232

#include <cstdio>

int area[3][3];
int dr[8][3] = {
	{0,0,0},
	{1,1,1},
	{2,2,2},
	{0,1,2},
	{0,1,2},
	{0,1,2},
	{0,1,2},
	{0,1,2}
};
int dc[8][3] = {
	{0,1,2},
	{0,1,2},
	{0,1,2},
	{0,0,0},
	{1,1,1},
	{2,2,2},
	{0,1,2},
	{2,1,0}
};
int kindArr[27];

int main(void) {
	int k = 0, t = 0;
	char tmp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %C", &tmp);
			area[i][j] = tmp - 'A';
		}
	}
	// count 1
	for (int i = 0; i < 8; i++) {
		int flag = 0;
		for (int j = 1; j < 3; j++) {
			if (area[dr[i][j]][dc[i][j]] == area[dr[i][j - 1]][dc[i][j - 1]]) flag++;
		}
		if (flag == 2) kindArr[area[dr[i][0]][dc[i][0]]]++;
	}
	for (int i = 0; i < 27; i++) if (kindArr[i] > 0) k++;

	// count team
	for (int p = 0; p < 26; p++) {
		for (int q = p + 1; q < 26; q++) {
			int flag = 0;
			for (int i = 0; i < 8; i++) {
				int a = 0, b = 0;
				for (int j = 0; j < 3; j++) {
					int nr = dr[i][j];
					int nc = dc[i][j];
					if (area[nr][nc] == p) a++;
					else if (area[nr][nc] == q) b++;
				}
				if ((a + b) == 3 && (a&&b)) {
					flag = 1;
					break;
				}
			}
			t += flag;
		}
	}
	printf("%d\n%d\n", k, t);
	return 0;
}
