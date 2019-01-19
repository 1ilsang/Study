//https://www.acmicpc.net/problem/5021
//http://1ilsang.blog.me/221429769958

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef long long LL;
const LL INF = 1LL << 52;
map<string, LL> mp;

int main(void) {
    string ans;
    LL tmp = 0;
    vector<vector<string>> v(3);
    string str;
    int n, m;
    scanf("%d %d", &n, &m);
    cin >> str;
    mp[str] = INF;

    for (int i = 0; i < n; i++) {
        cin >> str, v[0].push_back(str);
        cin >> str, v[1].push_back(str);
        cin >> str, v[2].push_back(str);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[v[0][j]] = (mp[v[1][j]] + mp[v[2][j]]) / 2;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        if(mp[str] > tmp) tmp = mp[str], ans = str;
    }
    cout << ans << endl;
    return 0;
}
