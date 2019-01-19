//https://www.acmicpc.net/problem/1238
//http://1ilsang.blog.me/221420532745

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1005;
const int INF = 987654321;

typedef pair<int, int> P;
int dist[MAX_N][2];
vector<vector<P>> v, vD(MAX_N), vR(MAX_N);
priority_queue<P> pq;

void dijkstra(int n, int m) {
    v = (m == 0) ? vD : vR;
    dist[n][m] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        int totalCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now][m] < totalCost) continue;
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int nextCost = v[now][i].second;
            if (totalCost + nextCost < dist[next][m]) {
                dist[next][m] = totalCost + nextCost;
                pq.push({-(totalCost + nextCost), next});
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < MAX_N; i++) fill(dist[i], dist[i] + 2, INF);
    int n, m, x;
    int ans = 0;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        vD[a].push_back({b, c});
        vR[b].push_back({a, c});
    }
    dijkstra(x, 0);
    dijkstra(x, 1);
    for (int i = 1; i <= n; i++) ans = max(ans, dist[i][0] + dist[i][1]);
    printf("%d\n", ans);
    return 0;
}
