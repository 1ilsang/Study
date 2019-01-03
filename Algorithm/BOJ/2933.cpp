//https://www.acmicpc.net/problem/2933
//http://1ilsang.blog.me/221433157431

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
const int MAX_N = 103;

int n, m;
int area[MAX_N][MAX_N];
int chk[MAX_N][MAX_N];

void input() {
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m; j++) {
            char tmp;
            if (i == n + 1) area[i][j] = 1;
            else {
                scanf(" %c", &tmp);
                tmp == 'x' ? area[i][j] = 1 : area[i][j] = 0;
            }
        }
    }
}

bool isMineralBoom(int r, int d) {
    bool ret = false;
    int c = d ? m : 0;
    while (true) {
        if (area[r][c] == 1) {
            area[r][c] = 0;
            ret = true;
            break;
        }
        if (d) {
            c--;
            if (c == 0) break;
        } else {
            c++;
            if (c == m) break;
        }
    }
    return ret;
}

void chkBottom(int r, int c) {
    chk[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (area[nr][nc] == 1 && chk[nr][nc] == 0) {
            chkBottom(nr, nc);
        }
    }
}

int getMinDist() {
    int ret = MAX_N;
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = n; j > 0; j--) {
            if (area[j][i] && chk[j][i]) cnt = 0;
            else if (area[j][i] == 0) cnt++;
            else if (area[j][i] == 1 && chk[j][i] == 0) {
                ret = min(ret, cnt);
                break;
            }
        }
    }
    return ret;
}

void reprintMineralMap(int dist) {
    for (int i = 1; i <= m; i++) {
        for (int j = n; j > 0; j--) {
            if(!chk[j][i] && area[j][i]) {
                area[j + dist][i] = 1;
                area[j][i] = 0;
            }
        }
    }
}

void printArea() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            area[i][j] ? printf("x") : printf(".");
        }
        puts("");
    }
}

int main(void) {
    int t;
    int d = 0;
    scanf("%d %d", &n, &m);
    memset(area, -1, sizeof(area));

    input();

    scanf("%d", &t);
    while (t--) {
        memset(chk, 0, sizeof(chk));

        int sr, minDist;
        scanf("%d", &sr);
        int r = n - sr + 1;

        if (!isMineralBoom(r, d++ % 2)) continue;

        chkBottom(n + 1, 0);
        minDist = getMinDist();
        if (minDist == MAX_N) continue;

        reprintMineralMap(minDist);
    }

    printArea();

    return 0;
}
