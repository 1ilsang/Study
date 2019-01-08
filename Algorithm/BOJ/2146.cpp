//https://www.acmicpc.net/problem/2146
//http://1ilsang.blog.me/221436934491

#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
const int MAX_N = 102;
const int INF = 200000001;

typedef struct {
    int r, c, p;
} Node;

int n;
int area[MAX_N][MAX_N];
int chk[MAX_N][MAX_N];
int qchk[MAX_N][MAX_N];
queue<Node> q;

void dfs(int r, int c) {
    chk[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!qchk[r][c] && area[nr][nc] == 0) {
            qchk[r][c] = 1;
            q.push({r, c, 0});
        }
        if (!chk[nr][nc] && area[nr][nc] == 1) dfs(nr, nc);
    }
}

int bfs() {
    int chk2[MAX_N][MAX_N];
    memset(chk2, 0, sizeof(chk2));
    int ret = INF;
    while (!q.empty()) {
        bool flag = false;
        int r = q.front().r;
        int c = q.front().c;
        int p = q.front().p;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!chk[nr][nc] && area[nr][nc] == 1 && qchk[nr][nc] == 0) {
                ret = p;
                flag = true;
                break;
            } else if (area[nr][nc] == 0 && chk2[nr][nc] == 0) {
                chk2[nr][nc] = 1;
                q.push({nr, nc, p + 1});
            }
        }
        if (flag) break;
    }
    return ret;
}

int main(void) {
    int ans = INF;
    scanf("%d", &n);
    memset(area, -1, sizeof(area));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &area[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!chk[i][j] && area[i][j]) {
                dfs(i, j);
                ans = min(ans, bfs());
                memset(qchk, 0, sizeof(qchk));
                while (!q.empty()) q.pop();
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
