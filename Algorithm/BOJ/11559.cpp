//https://www.acmicpc.net/problem/11559
//http://1ilsang.blog.me/221318591671

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector<pair<int, int>>v;
char puyoMap[13][7];
int check[13][7];
int checkPuyo[13][7];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int flag;
int ans;

int go(int row, int col) {
	char nowPuyo = puyoMap[row][col];
	int ret = 1;
	check[row][col] = 1;
	v.push_back(make_pair(row, col));
	
	for (int i = 0; i < 4; i++) {
		int nextRow = row + dr[i];
		int nextCol = col + dc[i];
		if (0 <= nextRow && nextRow < 12 && 0 <= nextCol && nextCol < 6
			&& check[nextRow][nextCol] == 0 && puyoMap[nextRow][nextCol] == nowPuyo) {
			ret += go(nextRow, nextCol);
		}
	}
	return ret;
}
char tmpPuyo[13][7];
void rePuyo() {
	for (int i = 0; i < 6; i++) {
		int k = 11;
		for (int j = 11; j >= 0; j--) {
			if (checkPuyo[j][i] == 0) {
				tmpPuyo[k--][i] = puyoMap[j][i];
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			puyoMap[i][j] = tmpPuyo[i][j];
		}
	}
}

int main(void) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %c", &puyoMap[i][j]);
		}
	}
	while (true) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (check[i][j] == 0 && puyoMap[i][j] != '.') {
					int tmp = go(i, j);
					if (tmp >= 4) {
						for (int i = 0; i < v.size(); i++) {
							int x = v[i].first;
							int y = v[i].second;
							checkPuyo[x][y] = 1;
						}
						flag = 1;
					}
					v.clear();
				}
			}
		}
		if (flag == 0) break;
		memset(tmpPuyo, '.', sizeof(tmpPuyo));
		rePuyo();
		memset(checkPuyo, 0, sizeof(checkPuyo));
		memset(check, 0, sizeof(check));
		
		ans++;
		flag = 0;
	}
	printf("%d\n", ans);
	return 0;
}
