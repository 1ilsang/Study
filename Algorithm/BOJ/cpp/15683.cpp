//https://www.acmicpc.net/problem/15683
//http://blog.naver.com/1ilsang/221352469553

//after 2018.10.17
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int d, r, c;
};

int n, m, k;
int area[9][9];
int chk[9][9];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<int> v;
vector<Node> cam;

int chkBlindSpot() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0 && area[i][j] == 0) ret++;
		}
	}
	return ret;
}

void chkGo(int r, int c, int i, int d) {
	for (int nc = c + dc[(v[i] + d) % 4], nr = r + dr[(v[i] + d) % 4];
		nr >= 0 && nc >= 0 && nr < n && nc < m && area[nr][nc] != 6;
		nc += dc[(v[i] + d) % 4], nr += dr[(v[i] + d) % 4]) {
			chk[nr][nc] = 1;
	}
}

void settingCam() {
	for (int i = 0; i < cam.size(); i++) {
		int r = cam[i].r;
		int c = cam[i].c;
		if (cam[i].d == 1) {
			chkGo(r, c, i, 0);
		}
		else if (cam[i].d == 2) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 2);
		}
		else if (cam[i].d == 3) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 3);
		}
		else if (cam[i].d == 4) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 2);
			chkGo(r, c, i, 3);
		}
		else if (cam[i].d == 5) {
			chkGo(r, c, i, 0);
			chkGo(r, c, i, 1);
			chkGo(r, c, i, 2);
			chkGo(r, c, i, 3);
		}
	}
}


int go(int lo) {
	if (v.size() == cam.size()) {
		memset(chk, 0, sizeof(chk));
		settingCam();
		return chkBlindSpot();
	}
	int ret = 999;
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		ret = min(ret, go(i));
		v.pop_back();
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &area[i][j]);
			if (0 < area[i][j] && area[i][j] < 6) cam.push_back({ area[i][j], i, j });
		}
	}
	printf("%d\n", go(0));
	return 0;
}


// before 2018.9.4
#include <cstdio>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//struct Node
//{
//	int r;
//	int c;
//	int v;
//};
//
//vector<Node> v;
//int area[9][9];
//int visit[9][9];
//int chkLo[9];
//int n, m;
//int wall;
//int ans = 987654321;
//
//int goR(int i) {
//	int nt = 1;
//	int cnt = 0;
//	while (area[v[i].r][v[i].c + nt] != 6 && v[i].c + nt < m) {
//		if (visit[v[i].r][v[i].c + nt] == 1 || area[v[i].r][v[i].c + nt]) {
//			nt++;
//		}
//		else {
//			visit[v[i].r][v[i].c + nt] = 1;
//			cnt++;
//			nt++;
//		}
//	}
//	return cnt;
//}
//
//int goD(int i) {
//	int cnt = 0;
//	int nt = 1;
//	while (area[v[i].r + nt][v[i].c] != 6 && v[i].r + nt < n) {
//		if (visit[v[i].r + nt][v[i].c] == 1 || area[v[i].r + nt][v[i].c]) {
//			nt++;
//		}
//		else {
//			visit[v[i].r + nt][v[i].c] = 1;
//			cnt++;
//			nt++;
//		}
//	}
//	return cnt;
//}
//
//int goL(int i) {
//	int cnt = 0;
//	int nt = 1;
//	while (area[v[i].r][v[i].c - nt] != 6 && v[i].c - nt >= 0) {
//		if (visit[v[i].r][v[i].c - nt] == 1 || area[v[i].r][v[i].c - nt]) {
//			nt++;
//		}
//		else {
//			visit[v[i].r][v[i].c - nt] = 1;
//			cnt++;
//			nt++;
//		}
//	}
//	return cnt;
//}
//
//int goU(int i) {
//	int cnt = 0;
//	int nt = 1;
//	while (area[v[i].r - nt][v[i].c] != 6 && v[i].r - nt >= 0) {
//		if (visit[v[i].r - nt][v[i].c] == 1 || area[v[i].r - nt][v[i].c]) {
//			nt++;
//		}
//		else {
//			visit[v[i].r - nt][v[i].c] = 1;
//			cnt++;
//			nt++;
//		}
//	}
//	return cnt;
//}
//
//void go(int lo) {
//
//	if (lo == v.size()) {
//		int ret = 0;
//		for (int i = 0; i < v.size(); i++) {
//			int cnt = 0;
//			switch (v[i].v)
//			{
//			case 1:
//				if (chkLo[i] == 0) {
//					cnt += goR(i);
//				}
//				else if (chkLo[i] == 1) {
//					cnt += goD(i);
//				}
//				else if (chkLo[i] == 2) {
//					cnt += goL(i);
//				}
//				else if (chkLo[i] == 3) {
//					cnt += goU(i);
//				}
//				break;
//			case 2:
//				if (chkLo[i] == 0 || chkLo[i] == 2) {
//					cnt += goL(i);
//					cnt += goR(i);
//				}
//				else if (chkLo[i] == 1 || chkLo[i] == 3) {
//					cnt += goD(i);
//					cnt += goU(i);
//				}
//				break;
//			case 3:
//				if (chkLo[i] == 0) {
//					cnt += goU(i);
//					cnt += goR(i);
//				}
//				else if (chkLo[i] == 1) {
//					cnt += goR(i);
//					cnt += goD(i);
//				}
//				else if (chkLo[i] == 2) {
//					cnt += goD(i);
//					cnt += goL(i);
//				}
//				else if (chkLo[i] == 3) {
//					cnt += goL(i);
//					cnt += goU(i);
//				}
//				break;
//			case 4:
//				if (chkLo[i] == 0) {
//					cnt += goL(i);
//					cnt += goU(i);
//					cnt += goR(i);
//				}
//				else if (chkLo[i] == 1) {
//					cnt += goU(i);
//					cnt += goR(i);
//					cnt += goD(i);
//				}
//				else if (chkLo[i] == 2) {
//					cnt += goR(i);
//					cnt += goD(i);
//					cnt += goL(i);
//				}
//				else if (chkLo[i] == 3) {
//					cnt += goD(i);
//					cnt += goL(i);
//					cnt += goU(i);
//				}
//				break;
//			case 5:
//				cnt += goR(i);
//				cnt += goD(i);
//				cnt += goL(i);
//				cnt += goU(i);
//			}
//			ret += cnt;
//		}
//		memset(visit, 0, sizeof(visit));
//		ret += wall + v.size();
//		ret = n * m - ret;
//		ans > ret ? ans = ret : ans = ans;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		chkLo[lo] = i;
//		go(lo + 1);
//	}
//}
//
//int main(void) {
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &area[i][j]);
//			if (area[i][j] != 6 && area[i][j] != 0) {
//				v.push_back({ i,j, area[i][j] });
//			}
//			if (area[i][j] == 6) wall++;
//		}
//	}
//	go(0);
//	printf("%d\n", ans);
//	return 0;
//}
