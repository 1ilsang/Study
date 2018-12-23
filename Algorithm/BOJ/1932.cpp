//https://www.acmicpc.net/problem/1932
//http://1ilsang.blog.me/221425510574

#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

vector<vector<int>> v;

const int MAX_N = 501;
int n;
int chk[MAX_N][MAX_N];

int go(int depth, int now) {
    int &ret = chk[depth][now];
    if(ret != -1) return ret;
    if (depth == n - 1) return v[depth][now];
    return ret = max(go(depth + 1, now) + v[depth][now],
               go(depth + 1, now + 1) + v[depth][now]);
}

int main(void) {
    memset(chk, -1, sizeof(chk));
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int tmp;
            scanf("%d", &tmp);
            v[i].push_back(tmp);
        }
    }
    printf("%d\n", go(0, 0));
    return 0;
}
