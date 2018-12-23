//https://www.acmicpc.net/problem/1389
//http://1ilsang.blog.me/221425438635

#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 200000001;
int n;

vector<vector<int>> v;

int dijkstra(int now) {
    int ret = 0;
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[now] = 0;
    pq.push({0, now});
    while(!pq.empty()) {
        int totalCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now] < totalCost) continue;
        for(int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            int nextCost = 1;
            if(totalCost + nextCost < dist[next]) {
                dist[next] = totalCost + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }
    for(int i = 1; i <= n; i++) ret += dist[i];

    return ret;
}

int main(void){
    int m, ans;
    int ansV = INF;

    scanf("%d %d", &n, &m);
    v.resize(n + 1);
    for(int i = 0 ; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n; i++) {
        int tmp = dijkstra(i);
        if(tmp < ansV) ansV = tmp, ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
