//https://www.acmicpc.net/problem/11403
//http://1ilsang.blog.me/221427680650

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 101;

vector<vector<int>> v;
int chk[MAX_N][MAX_N], dist[MAX_N][MAX_N];

void go(int strt, int now) {
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (chk[strt][next] == 0) {
            chk[strt][next] = 1;
            dist[strt][next] = 1;
            go(strt, next);
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            scanf("%d", &tmp);
            if(tmp == 1) v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        go(i, i);
        memset(chk, 0, sizeof(chk));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dist[i][j]);
        }
        puts("");
    }
    return 0;
}
