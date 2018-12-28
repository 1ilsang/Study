//https://www.acmicpc.net/problem/3187
//http://1ilsang.blog.me/221429331774

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 253;
const int dr[4] = {0,1,0,-1};
const int dc[4] = {1,0,-1,0};

int chk[MAX_N][MAX_N];
int area[MAX_N][MAX_N];
int n, m, v, k;

void go(int r, int c) {
    chk[r][c] = 1;

    if(area[r][c] == 118) v++;
    else if(area[r][c] == 107) k++;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(area[nr][nc] != 0 && area[nr][nc] != 35 && chk[nr][nc] == 0)
            go(nr, nc);
    }
}

int main(void){
    pair<int, int> ans;
    ans.first = ans.second = 0;

    scanf("%d %d", &n, &m);
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1 ; j <= m; j++) {
            scanf(" %c", &area[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1 ; j <= m; j++) {
            if(chk[i][j] == 0 && area[i][j] != 35) {
                go(i, j);
                if(v >= k) ans.second += v;
                else ans.first += k;
                v = k = 0;
            }
        }
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
