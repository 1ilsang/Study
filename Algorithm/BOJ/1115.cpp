//https://www.acmicpc.net/problem/1115
//http://1ilsang.blog.me/221427323954

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    int n, ans, k;
    ans = k = 0;

    vector<int> v, chk;
    scanf("%d", &n);
    chk.resize(n);

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    while (true) {
        if (chk[v[k]] == 1) {
            int flag = 0, cnt = 0;
            ans++;
            for (int i = 0; i < chk.size(); i++) {
                if (chk[i] == 0) {
                    k = i;
                    flag = 1;
                    break;
                }
                else cnt++;
            }
            if(flag == 0 || cnt == chk.size()) break;
        } else chk[v[k]] = 1, k = v[k];
    }
    printf("%d\n", ans == 1 ? 0 : ans);
    return 0;
}
