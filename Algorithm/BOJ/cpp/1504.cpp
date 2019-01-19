//https://www.acmicpc.net/problem/1504
//http://1ilsang.blog.me/221421559011

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
#define INF 200000001
using namespace std;
typedef pair<int, int> P;
vector<vector<P>> adj;
int n, m;

int djs(int s, int e) {
    vector<int> visited(n + 1, 0);
    vector<int> dist(n + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({ 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dist[now]) continue;
        visited[now] = 1;
        for (auto& i : adj[now]) {
            int next = i.first;
            int nextCost = i.second;
            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push({ dist[next], next });
            }
        }
    }
    return dist[e];
}

int main() {
    scanf("%d %d", &n, &m);
    adj.resize(n + 1);
    int u, v, w, m1, m2;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    scanf("%d %d", &m1, &m2);
    long long ans = min(djs(1, m1) + djs(m1, m2) + djs(m2, n),
            djs(1, m2) + djs(m2, m1) + djs(m1, n));
    if (ans > INF)	printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}
