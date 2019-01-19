//https://www.acmicpc.net/problem/10816
//http://1ilsang.blog.me/221400464636

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int go(vector<pair<int, int>> &vv, int num, int l, int r) {
	int ret = 0;
    int mid = (l + r) / 2;

    if(l > r) return 0;
    if(vv[mid].first == num) return vv[mid].second;
    
    if(num < vv[mid].first) ret = go(vv, num, l, mid - 1);
    else if(num > vv[mid].first) ret = go(vv, num, mid + 1, r);
    
    return ret;
}
 
int main() {
    int n, m, tmp;
    vector<int> v;
    scanf("%d", &n);
    v.resize(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
 
    vector<pair<int, int>> vv;
    vv.push_back({v[0], 1});
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == vv[idx].first) {
            vv[idx].second++;
        }
        else {
            vv.push_back({v[i], 1});
            idx++;
        }
    }
    
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &tmp);
        printf("%d ", go(vv, tmp, 0, vv.size() - 1));
    }
    printf("\n");
    return 0;
}
