//https://www.acmicpc.net/problem/15685
//http://1ilsang.blog.me/221348658499


//after

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v, ans;
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };

int chkSquare() {
	int ret = 0;
	for (int i = 0; i < ans.size(); i++) {
		int r = ans[i].first;
		int c = ans[i].second;
		int cnt = 0;
		for (int j = 0; j < ans.size(); j++) {
			if (i == j)continue;
			int nr = ans[j].first;
			int nc = ans[j].second;
			if (r == nr && c + 1 == nc) cnt++;
			else if (r + 1 == nr && c == nc) cnt++;
			else if (r + 1 == nr && c + 1 == nc) cnt++;
			if (cnt == 3) {
				ret++;
				break;
			}
			if (r + 1 < nr) break;
		}
	}
	return ret;
}

void go(int g) {
	if (g == 0) {
		for (int j = 0; j < v.size(); j++) ans.push_back(v[j]);
		return;
	}
	vector<pair<int, int>> tmp;
	pair<int, int> now = v.back();
	for (int i = v.size() - 2; i >= 0; i--) {
		int r = v[i + 1].first;
		int c = v[i + 1].second;
		int pr = v[i].first;
		int pc = v[i].second;
		int nd;
		if (r == pr && pc < c) nd = 1;
		else if (r == pr && c < pc) nd = 3;
		else if (c == pc && r < pr) nd = 2;
		else if (c == pc && r > pr) nd = 0;
		int nr = now.first + dr[nd];
		int nc = now.second + dc[nd];
		tmp.push_back({ nr, nc });
		now = { nr, nc };
	}
	for (int i = 0; i < tmp.size(); i++) v.push_back(tmp[i]);
	go(g - 1);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		v.push_back({ y,x });
		v.push_back({ y + dr[d], x + dc[d] });
		go(g);
		v.clear();
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", chkSquare());
	return 0;
}

// Before

//#include <cstdio>
//#include <vector>
//using namespace std;
//
//vector<pair<int, int>>v;
//int area[101][101];
//int dr[4] = { 0,-1,0,1 };
//int dc[4] = { 1,0,-1,0 };
//int n;
//
//int main(void) {
//	int ans = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int x, y, d, g;
//		scanf("%d %d %d %d", &x, &y, &d, &g);
//		v.push_back({ x, y });
//		area[y][x] = 1;
//		// d 로 확인해서 0 세대를 만들어 준다.
//		switch (d) {
//		case 0:
//			v.push_back({ x + 1, y });
//			area[y][x + 1] = 1;
//			break;
//		case 1:
//			v.push_back({ x, y - 1 });
//			area[y - 1][x] = 1;
//			break;
//		case 2:
//			v.push_back({ x - 1,y });
//			area[y][x - 1] = 1;
//			break;
//		case 3:
//			v.push_back({ x, y + 1 });
//			area[y + 1][x] = 1;
//			break;
//		}
//
//		// g 번 세대를 돈다.
//		for (int gt = 0; gt < g; gt++) {
//			// 배열 값만큼 돌려준다.
//			int k = v.size();
//			int direction;
//			// 이 전의 방향이 뭔지 확인한다.
//			//		printf("\n\n ::%d::============\n", gt + 1);
//			for (int i = k - 2; i >= 0; i--) {
//				// 방향은 무조건 상하좌우 안에 있다.
//				int baseX = v[i + 1].first;
//				int baseY = v[i + 1].second;
//				int prevX = v[i].first;
//				int prevY = v[i].second;
//				//	printf(" %d %d, %d %d", baseX, baseY, prevX, prevY);
//				for (int z = 0; z < 4; z++) {
//					if (baseX + dc[z] == prevX && baseY + dr[z] == prevY) {
//						// 방향을 찾았으면 + 1 방향으로 설정한다. (그리는 방향이 +1 이므로)
//						direction = z - 1;
//						if (direction == -1) direction = 3;
//						//			printf("  z: %d  direction : %d\n", z, direction);
//						break;
//					}
//				}
//				int nextX = v.back().first + dc[direction];
//				int nextY = v.back().second + dr[direction];
//				// 다음 방향을 맵에 체크하고 push 해준다(다음 세대 검정용)
//				area[nextY][nextX] = 1;
//				//		printf("   %d %d\n", nextX, nextY);
//				v.push_back({ nextX, nextY });
//			}
//		}
//		v.clear();
//	}
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 100; j++) {
//			/*	if (area[i][j]) {
//			printf(" %d %d\n", i, j);
//			}*/
//			if (area[i][j] && area[i][j + 1] && area[i + 1][j] && area[i + 1][j + 1]) {
//				ans++;
//			}
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}
