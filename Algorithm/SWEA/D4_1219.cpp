//
// Created by user on 2018. 6. 29..
//
//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14geLqABQCFAYD&categoryId=AV14geLqABQCFAYD&categoryType=CODE

#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> v;
int ans;

int main(void) {
    int t, cnt;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmpN, tmpV;
            scanf("%d %d", &tmpN, &tmpV);
            v[tmpN].push_back(tmpV);
        }

        printf("#%d %d\n", cnt++, ans);
        v.clear();
    }
    return 0;
}