//https://www.acmicpc.net/problem/16235
//http://1ilsang.blog.me/221444955903

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 13;
const int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int area[MAX_N][MAX_N];
int A[MAX_N][MAX_N];
vector<int> tree[MAX_N][MAX_N];

int n;

void springSummerWars() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tree[i][j].empty()) continue;
            int sum = 0;
            vector<int> nTree;
            sort(tree[i][j].begin(), tree[i][j].end());

            for (int k = 0; k < tree[i][j].size(); k++) {
                if (area[i][j] >= tree[i][j][k]) {
                    area[i][j] -= tree[i][j][k];
                    nTree.push_back(tree[i][j][k] + 1);
                } else sum += (tree[i][j][k] / 2);
            }
            tree[i][j].clear();
            for (int e: nTree) tree[i][j].push_back(e);
            area[i][j] += sum;
        }
    }
}

void fallingSlowly() {
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            for (int i = 0; i < tree[r][c].size(); i++) {
                if (tree[r][c][i] % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr > 0 && nc > 0 && nr <= n && nc <= n) {
                            tree[nr][nc].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winnterIsComming() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) area[i][j] += A[i][j];
}

int main(void) {
    int ans = 0;
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
            area[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        tree[a][b].push_back(c);
    }
    while (k--) {
        springSummerWars();
        fallingSlowly();
        winnterIsComming();
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans += tree[i][j].size();
    printf("%d\n", ans);
    return 0;
}
