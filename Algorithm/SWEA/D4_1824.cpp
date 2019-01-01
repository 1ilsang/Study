//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yLUiKDUoDFAUx&categoryId=AV4yLUiKDUoDFAUx&categoryType=CODE
//http://1ilsang.blog.me/221431770382

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

char area[22][22];
int chk[22][22][4][15];
int memory;
int R, C;

bool go(int r, int c, int d, int depth) {
    bool ret = false;

    if ('0' <= area[r][c] && area[r][c] <= '9') memory = area[r][c] - '0';
    else if (area[r][c] == '>' || (area[r][c] == '_' && memory == 0)) d = 0;
    else if (area[r][c] == 'v' || (area[r][c] == '|' && memory == 0)) d = 1;
    else if (area[r][c] == '<' || area[r][c] == '_') d = 2;
    else if (area[r][c] == '^' || area[r][c] == '|') d = 3;
    else if (area[r][c] == '+') memory = (memory + 1) % 16;
    else if (area[r][c] == '-' && memory == 0) memory = 15;
    else if (area[r][c] == '-') memory -= 1;
    else if (area[r][c] == '@') return true;

    if(chk[r][c][d][memory] == 1) return false;
    else chk[r][c][d][memory] = 1;

    int nr = r + dr[d];
    int nc = c + dc[d];
    if(nr == 0) nr = R;
    else if(nr == R + 1) nr = 1;
    if(nc == 0) nc = C;
    else if(nc == C + 1) nc = 1;

    if(area[r][c] == '?') {
        for(int i = 0 ; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr == 0) nr = R;
            else if(nr == R + 1) nr = 1;
            if(nc == 0) nc = C;
            else if(nc == C + 1) nc = 1;
            ret = max(go(nr, nc, i, depth + 1), ret);
        }
        return ret;
    }
    else return max(ret, go(nr, nc, d, depth + 1));
}

int main(void) {
    int tcase;
    scanf("%d", &tcase);
    for (int t = 1; t <= tcase; t++) {
        memset(area, -1, sizeof(area));
        memset(chk, -1, sizeof(chk));
        scanf("%d %d", &R, &C);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                scanf(" %c", &area[i][j]);
            }
        }
        printf("#%d %s\n", t, go(1, 1, 0, 0) ? "YES" : "NO");
        memory = 0;
    }
    return 0;
}
