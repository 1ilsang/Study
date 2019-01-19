//https://www.acmicpc.net/problem/2210
//http://1ilsang.blog.me/221437086301

#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int area[6][6];
set<int> st;

void backtracking(int r, int c, int depth, int n) {
    if (depth == 6) {
        st.insert(n);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr <= 5 && nc <= 5 && nr > 0 && nc > 0) {
            backtracking(nr, nc, depth + 1, n * 10 + area[nr][nc]);
        }
    }
}

int main(void) {
    for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) scanf("%d", &area[i][j]);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++) {
            backtracking(i, j, 1, area[i][j]);
        };
    printf("%d\n", st.size());
    return 0;
}
