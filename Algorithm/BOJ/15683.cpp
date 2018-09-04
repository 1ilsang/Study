//https://www.acmicpc.net/problem/15683
//http://blog.naver.com/1ilsang/221352469553

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

int goR(int i) {
	int nt = 1;
	int cnt = 0;
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
	return cnt;
}

int goD(int i) {
	int cnt = 0;
	int nt = 1;
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
	return cnt;
}

int goL(int i) {
	int cnt = 0;
	int nt = 1;
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
	return cnt;
}

int goU(int i) {
	int cnt = 0;
	int nt = 1;
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
	return cnt;
}

void go(int lo) {

	if (lo == v.size()) {
		int ret = 0;
		for (int i = 0; i < v.size(); i++) {
			int cnt = 0;
			switch (v[i].v)
			{
			case 1:
				if (chkLo[i] == 0) {
					cnt += goR(i);
				}
				else if (chkLo[i] == 1) {
					cnt += goD(i);
				}
				else if (chkLo[i] == 2) {
					cnt += goL(i);
				}
				else if (chkLo[i] == 3) {
					cnt += goU(i);
				}
				break;
			case 2:
				if (chkLo[i] == 0 || chkLo[i] == 2) {
					cnt += goL(i);
					cnt += goR(i);
				}
				else if (chkLo[i] == 1 || chkLo[i] == 3) {
					cnt += goD(i);
					cnt += goU(i);
				}
				break;
			case 3:
				if (chkLo[i] == 0) {
					cnt += goU(i);
					cnt += goR(i);
				}
				else if (chkLo[i] == 1) {
					cnt += goR(i);
					cnt += goD(i);
				}
				else if (chkLo[i] == 2) {
					cnt += goD(i);
					cnt += goL(i);
				}
				else if (chkLo[i] == 3) {
					cnt += goL(i);
					cnt += goU(i);
				}
				break;
			case 4:
				if (chkLo[i] == 0) {
					cnt += goL(i);
					cnt += goU(i);
					cnt += goR(i);
				}
				else if (chkLo[i] == 1) {
					cnt += goU(i);
					cnt += goR(i);
					cnt += goD(i);
				}
				else if (chkLo[i] == 2) {
					cnt += goR(i);
					cnt += goD(i);
					cnt += goL(i);
				}
				else if (chkLo[i] == 3) {
					cnt += goD(i);
					cnt += goL(i);
					cnt += goU(i);
				}
				break;
			case 5:
				cnt += goR(i);
				cnt += goD(i);
				cnt += goL(i);
				cnt += goU(i);
			}
			ret += cnt;
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
