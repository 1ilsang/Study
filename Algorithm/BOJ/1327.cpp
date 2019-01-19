//https://www.acmicpc.net/problem/1327
//http://1ilsang.blog.me/221445986259

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

string now, target;
set<string> chk;

int bfs(int k) {
    int ret = -1;
    queue<pair<string, int>> q;
    q.push({now, 0});

    while(!q.empty()) {
        string now = q.front().first;
        int p = q.front().second;
        q.pop();
        if(now == target) {
            ret = p;
            break;
        }
        for(int i = 0; i <= now.size() - k; i++) {
            string tmp = now;
            reverse(tmp.begin() + i, tmp.begin() + i + k);
            if(chk.count(tmp) == 0) {
                chk.insert(tmp);
                q.push({tmp, p + 1});
            }
        }
    }
    return ret;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        char tmp;
        scanf(" %c", &tmp);
        now += tmp;
    }
    target = now;
    sort(target.begin(), target.end());
    printf("%d\n", bfs(k));
    return 0;
}
