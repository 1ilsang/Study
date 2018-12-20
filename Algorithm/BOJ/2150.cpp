//https://www.acmicpc.net/problem/2150
//http://1ilsang.blog.me/221423719269

#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

const int MAX_N = 10005;
typedef vector<vector<int>> VVI;
VVI v, ans;
stack<int> stk;
int stkChk[MAX_N], chk[MAX_N];
int cnt = 0;

void go(int now) {
    int nowN = cnt;
    stkChk[now] = cnt++;
    chk[now] = 1;
    stk.push(now);

    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (stkChk[next] == -1) go(next);
        if (chk[next]) stkChk[now] = min(stkChk[now], stkChk[next]);
    }
    if (nowN == stkChk[now]) {
        vector<int> k;
        while (true) {
            int top = stk.top();
            stk.pop();
            chk[top] = 0;
            k.push_back(top);
            if (top == now) break;
        }
        sort(k.begin(), k.end());
        ans.push_back(k);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }

    memset(stkChk, -1, sizeof(stkChk));
    for (int i = 1; i <= n; i++) if (stkChk[i] == -1) go(i);
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("-1\n");
    }

    return 0;
}
