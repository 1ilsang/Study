//https://www.acmicpc.net/problem/1913

#include<cstdio>

const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,1,0,-1};

int n, m, ar, ac, r, c, d, nr, nc;
int area[999][999];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = n * n; i > 0; i--) {
        area[r][c] = i;
        if(area[r][c] == m) ar = r, ac = c;
        nr = r + dr[d];
        nc = c + dc[d];
        if(nr < 0 || nc < 0 || nr >= n || nc >= n || area[nr][nc]) d = (d + 1) % 4;
        r += dr[d];
        c += dc[d];
    }
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            printf("%d ", area[i][j]);
        }puts("");
    }
    printf("%d %d\n", ar + 1, ac + 1);
    return 0;
}
