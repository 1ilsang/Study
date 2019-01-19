//https://www.acmicpc.net/problem/9663
//http://1ilsang.blog.me/221436112808

#include <cstdio>
#include <cstring>

const int MAX_N = 15;

int n;
bool ld[MAX_N * 2];
bool rd[MAX_N * 2];
bool col[MAX_N];

int go(int r, int c, int depth) {
    if (depth == 1) return 1;
    int ret = 0;

    col[c] = rd[r + c] = ld[r - c + MAX_N] = true;

    for (int j = 0; j < n; j++) {
        int nrd = r + 1 + j;
        int nld = r + 1 - j + MAX_N;
        if (!rd[nrd] && !ld[nld] && !col[j]) {
            ret += go(r + 1, j, depth - 1);
        }
    }

    col[c] = rd[r + c] = ld[r - c + MAX_N] = false;
    return ret;
}

int main(void) {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) ans += go(0, i, n);
    printf("%d\n", ans);
    return 0;
}
