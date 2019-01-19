//https://www.acmicpc.net/problem/9372
//http://1ilsang.blog.me/221425452162

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
int n, m;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        v.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        printf("%d\n", n - 1);
    }
    return 0;
}
