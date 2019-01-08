//https://www.acmicpc.net/problem/1726
//http://1ilsang.blog.me/221436805517

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int p, d, r, c;
} Node;
typedef struct {
    int r, c, d;
} ND;

//동서남북
const int dr[5] = {0, 0, 0, 1, -1};
const int dc[5] = {0, 1, -1, 0, 0};
const int MAX_N = 102;

ND sp, ep;

int area[MAX_N][MAX_N];
int chk[MAX_N][MAX_N][4];
int n, m;

int bfs(int r, int c, int d) {
    int ret = 0;
    queue<Node> q;
    q.push({0, d, r, c});
    chk[r][c][d] = 1;

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        int p = q.front().p;
        q.pop();
        if (r == ep.r && c == ep.c) {
            if (d == ep.d) ret = p;
            else if ((ep.d == 1 && d == 2) || (ep.d == 2 && d == 1)
                     || (ep.d == 3 && d == 4) || (ep.d == 4 && d == 3))
                ret = p + 2;
            else ret = p + 1;
            break;
        }
        int turnFlag = 0;
        for (int i = 0; i < 4; i++) {
            int nd;
            if (i == 0) nd = d;
            else if (i == 1) {
                nd = d - 2;
                turnFlag = 1;
                if (nd == 0) nd = 3;
                else if (nd == -1) nd = 4;
            } else if (i == 2) {
                nd = d + 2;
                turnFlag = 1;
                if (nd == 5) nd = 2;
                else if (nd == 6) nd = 1;
            } else if (i == 3) {
                turnFlag = 2;
                if (d == 1) nd = 2;
                else if (d == 2) nd = 1;
                else if (d == 3) nd = 4;
                else if (d == 4) nd = 3;
            }
            for (int j = 3; j > 0; j--) {
                bool flag = true;
                int nr = r + dr[nd] * j;
                int nc = c + dc[nd] * j;
                for (int k = j; k > 0; k--) {
                    int tnr = r + dr[nd] * k;
                    int tnc = c + dc[nd] * k;
                    if (tnr <= 0 || tnc <= 0 || tnr > n || tnc > m || chk[tnr][tnc][nd] || area[tnr][tnc]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    chk[nr][nc][nd] = 1;
                    q.push({p + 1 + turnFlag, nd, nr, nc});
                }
            }
        }
    }
    return ret;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &area[i][j]);
        }
    }
    scanf("%d %d %d", &sp.r, &sp.c, &sp.d);
    scanf("%d %d %d", &ep.r, &ep.c, &ep.d);
    printf("%d\n", bfs(sp.r, sp.c, sp.d));
    return 0;
}
