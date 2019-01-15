//https://www.acmicpc.net/problem/1194
//http://1ilsang.blog.me/221442344756

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
const int MAX_N = 55;

typedef struct {
    int r, c, p, key;
} Node;

int n, m;
char area[MAX_N][MAX_N];
int chk[MAX_N][MAX_N][1 << 7];

int bfs(int r, int c) {
    int ret = -1;
    queue<Node> q;
    q.push({r, c, 0, 0});
    chk[r][c][0]=1;
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int p = q.front().p;
        int key = q.front().key;
        q.pop();
//        printf("%d %d %d %d\n", r,c,p,key);
        if (area[r][c] == '1') {
            ret = p;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nk = key;
            if (area[nr][nc] != -1 && area[nr][nc] != '#') {
                if (area[nr][nc] >= 'a' && area[nr][nc] <= 'f') {
                    nk |= 1 << (area[nr][nc] - 'a');
                } else if (area[nr][nc] >= 'A' && area[nr][nc] <= 'F') {
                    if (!(key & 1 << (area[nr][nc] - 'A'))) continue;
                }
                if (!chk[nr][nc][nk]){
                    chk[nr][nc][nk] = 1;
                    q.push({nr, nc, p + 1, nk});
                }
            }
        }
    }

    return ret;
}

int main(void) {
    int sr, sc;
    memset(area, -1, sizeof(area));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &area[i][j]);
            if (area[i][j] == '0') sr = i, sc = j;
        }
    }
    printf("%d\n", bfs(sr, sc));
    return 0;
}

