//https://www.acmicpc.net/problem/4485
//http://1ilsang.blog.me/221434983123

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 126;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

typedef pair<int, pair<int, int>> ppi;

int area[MAX_N][MAX_N];

int bfs(int n) {
    int dist[MAX_N][MAX_N];
    memset(dist, -1, sizeof(dist));

    priority_queue<ppi> pq;
    pq.push({-area[0][0], {0, 0}});
    dist[0][0] = area[0][0];

    while (!pq.empty()) {
        int p = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(dist[r][c] != -1 && p > dist[r][c]) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nc < n && nr < n){
                int np = p + area[nr][nc];
                if(dist[nr][nc] == -1 || np < dist[nr][nc]){
                    dist[nr][nc] = np;
                    pq.push({-np, {nr, nc}});
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main() {
    int t = 1;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &area[i][j]);
        printf("Problem %d: %d\n", t++, bfs(n));
    }
    return 0;
}
