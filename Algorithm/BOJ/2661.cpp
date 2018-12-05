//https://www.acmicpc.net/problem/2661
//http://1ilsang.blog.me/221412823544

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool chkPermutation(vector<int> v) {
    for (int i = 1; i <= v.size() / 2; i++) {
        int chk = 0;
        for (int j = 0; j < v.size() - i; j++) {
            if (v[j] == v[j + i]) chk++;
            else chk = 0;
            if (chk == i) return false;
        }
    }
    return true;
}

void go(vector<int> v, int n, int lo) {

    if (v.size() == n) {
        if (chkPermutation(v)) {
            for (int i = 0; i < v.size(); i++) printf("%d", v[i]);
            exit(0);
        } else return;
    }

    for (int j = 1; j <= 3; j++) {
        v.push_back(j);
        if (!chkPermutation(v)) {
            v.pop_back();
            continue;
        }
        go(v, n, lo + 1);
        v.pop_back();
    }
}

int main(void) {
    vector<int> v;
    int n;
    scanf("%d", &n);
    go(v, n, 0);
    return 0;
}
