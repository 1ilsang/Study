//https://www.acmicpc.net/problem/15683
//

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct Node
{
	int r;
	int c;
	int v;
};

vector<Node> v;
int area[9][9];
int visit[9][9];
int chkLo[9];
int n, m;
int wall;
int ans = 987654321;

// lo 는 현재 위치
void go(int lo) {

	if (lo == v.size()) {
		// 해당 내용 출력.
	/*	for (int i = 0; i < v.size()	; i++) {
			printf(" %d", chkLo[i]);
		}puts("");*/
		int ret = 0;
		for (int i = 0; i < v.size(); i++) {
			// 1 1 1. 1 1 2. 1 1 3 ---
			int cnt = 1;
			int nt = 1;
			switch (v[i].v)
			{
			case 1:
				if (chkLo[i] == 0) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 1) {
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 2) {
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 3) {
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				break;
			case 2:
				if (chkLo[i] == 0 || chkLo[i] == 2) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 1 || chkLo[i] == 3) {
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				break;
			case 3:
				if (chkLo[i] == 0) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 1) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 2) {
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 3) {
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				break;
			case 4:
				if (chkLo[i] == 0) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 1) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 2) {
					while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
						if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c + nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
				}
				else if (chkLo[i] == 3) {
					while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
						if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r + nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
						if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
							nt++;
						}
						else {
							visit[v[i].r][v[i].c - nt] = 1;
							cnt++;
							nt++;
						}
					}
					nt = 1;
					while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
						if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
							nt++;
						}
						else {
							visit[v[i].r - nt][v[i].c] = 1;
							cnt++;
							nt++;
						}
					}
				}
				break;
			case 5:
				while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
					if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
						nt++;
					}
					else {
						visit[v[i].r][v[i].c + nt] = 1;
						cnt++;
						nt++;
					}
				}
				nt = 1;
				while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
					if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
						nt++;
					}
					else {
						visit[v[i].r + nt][v[i].c] = 1;
						cnt++;
						nt++;
					}
				}
				nt = 1;
				while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
					if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
						nt++;
					}
					else {
						visit[v[i].r][v[i].c - nt] = 1;
						cnt++;
						nt++;
					}
				}
				nt = 1;
				while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
					if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
						nt++;
					}
					else {
						visit[v[i].r - nt][v[i].c] = 1;
						cnt++;
						nt++;
					}
				}
			}
			ret += (cnt - 1);
		}
		memset(visit, 0, sizeof(visit));
		ret += wall + v.size();
		ret = n * m - ret;
		ans > ret ? ans = ret : ans = ans;
		return;
	}

	for (int i = 0; i < 4; i++) {
		chkLo[lo] = i;
		go(lo + 1);
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
			if (area[i][j] != 6 && area[i][j] != 0) {
				v.push_back({ i,j, area[i][j] });
			}
			if (area[i][j] == 6) wall++;
		}
	}
	go(0);
	printf("%d\n", ans);
	return 0;
}
