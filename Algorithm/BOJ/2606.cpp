//https://www.acmicpc.net/problem/2606
//http://1ilsang.blog.me/221418711887

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

int chk[1001];
typedef vector<vector<int>> VV;
typedef pair<int, int> P;

VV v;

int go(int now) {
    chk[now] = 1;
    int ret = 1;
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (!chk[next]) ret += go(next);
    }
    return ret;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    printf("%d\n", go(1) - 1);
    return 0;
}
