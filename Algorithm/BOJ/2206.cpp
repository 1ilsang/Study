//https://www.acmicpc.net/problem/2206
//http://1ilsang.blog.me/221419824897

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;
typedef vector<vector<int>> VV;
typedef pair<int, int> P;
typedef struct {
    int r, c, p;
} Node;

int chk[1002][1002][2];
int area[1002][1002];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int n, m;

int go(int sr, int sc) {
    int ret = -1;
    queue<Node> q;
    q.push({sr, sc, 1});
    chk[sr][sc][1] = 1;
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int p = q.front().p;
        q.pop();
        if (r == n - 1 && c == m - 1) {
            ret = chk[r][c][p];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                if (p && area[nr][nc]) {
                    chk[nr][nc][p - 1] = chk[r][c][p] + 1;
                    q.push({nr, nc, p - 1});
                } else if (!area[nr][nc] && !chk[nr][nc][p]) {
                    chk[nr][nc][p] = chk[r][c][p] + 1;
                    q.push({nr, nc, p});
                }
            }
        }
    }
    return ret;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1d", &area[i][j]);
        }
    }
    printf("%d\n", go(0, 0));
    return 0;
}
