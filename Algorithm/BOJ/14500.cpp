//https://www.acmicpc.net/problem/14500
//http://1ilsang.blog.me/221356332423

//2018.10
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int area[501][501];
int tetM[20][2][4] = {
	{{0,0,0,0}, {0,1,2,3}}, // ㅡ
	{{0,1,2,3}, {0,0,0,0}}, // l
	{{0,0,1,1}, {0,1,0,1}}, // ㅁ
	{{0,0,0,1}, {0,1,2,1}}, // ㅜ
	{{0,1,1,2}, {0,0,1,0}}, //ㅏ
	{{0,1,1,1}, {1,0,1,2}}, // ㅗ
	{{0,1,1,2}, {1,0,1,1}}, // ㅓ
	{{0,1,2,2}, {0,0,0,1}}, // L
	{{0,1,1,1}, {2,0,1,2}}, // rㄴ
	{{0,0,1,2}, {0,1,1,1}}, // lㄱ
	{{0,0,0,1}, {0,1,2,0}}, // rㄱ
	{{0,1,2,2}, {1,1,0,1}},
	{{0,0,0,1}, {0,1,2,2}}, // ㄱ
	{{0,0,1,2}, {0,1,0,0}},
	{{0,1,1,1}, {0,0,1,2}},
	{{0,1,1,2}, {0,0,1,1}},
	{{0,0,1,1}, {1,2,0,1}},
	{{0,1,1,2}, {1,0,1,0}},
	{{0,0,1,1}, {0,1,1,2}}
};

int go(int r, int c) {
	int ret = 0;
	for (int z = 0; z < 19; z++) {
		int tmp = 0;
		for (int i = 0; i < 4; i++) {
			int nr = r + tetM[z][0][i];
			int nc = c + tetM[z][1][i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
				tmp += area[nr][nc];
			}
			else {
				tmp = 0;
				break;
			}
		}
		ret = max(ret, tmp);
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)scanf("%d", &area[i][j]);
	int ans = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) ans = max(ans, go(i, j));
	printf("%d\n", ans);
	return 0;
}

///////////////////////////////////////////////////////////
//2018.09
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int n, m;
//int area[501][501];
//int ans;
//
//vector<pair<int, int>> M = { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } },
//M2 = { { 0,0 },{ 0,1 },{ 0,2 },{ 0,3 } }, O = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } },
//Z = { { 0,0 },{ 1,0 },{ 1,1 },{ 2,1 } }, Z2 = { { 1,0 },{ 1,1 },{ 0,1 },{ 0,2 } },
//T = { { 0,0 },{ 1,0 },{ 1,1 },{ 2,0 } }, T2 = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,1 } },
//T3 = { { 1,0 },{ 0,1 },{ 1,1 },{ 2,1 } }, T4 = { { 1,0 },{ 0,1 },{ 1,1 },{ 1,2 } },
//L = { { 0,0 },{ 1,0 },{ 2,0 },{ 2,1 } }, L2 = { { 1,0 },{ 0,0 },{ 0,1 },{ 0,2 } },
//L3 = { { 0,0 },{ 0,1 },{ 1,1 },{ 2,1 } }, L4 = { { 0,2 },{ 1,0 },{ 1,1 },{ 1,2 } },
//J = { { 0,1 },{ 1,1 },{ 2,0 },{ 2,1 } }, J2 = { { 0,0 },{ 1,0 },{ 1,1 },{ 1,2 } },
//J3 = { { 0,0 },{ 0,1 },{ 1,0 },{ 2,0 } }, J4 = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,2 } },
//h = { { 0,1 },{ 1,0 },{ 1,1 },{ 2,0 } }, h2 = { { 0,0 },{ 0,1 },{ 1,1 },{ 1,2 } };
//vector<vector<pair<int, int>>> V = { M,M2,O,Z,Z2,T,T2,T3,T4,L,L2,L3,L4,J,J2,J3,J4,h,h2 };
//
//void go(int r, int c) {
//	for (int i = 0; i < V.size(); i++) {
//		int ret = 0;
//		int flag = 0;
//		for (int j = 0; j < 4; j++) {
//			int nr = r + V[i][j].first;
//			int nc = c + V[i][j].second;
//			if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
//				ret += area[nr][nc];
//			}
//			else {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			ret > ans ? ans = ret : ans = ans;
//		}
//	}
//}
//
//int main(void) {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &area[i][j]);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			go(i, j);
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}
