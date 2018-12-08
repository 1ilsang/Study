//https://www.acmicpc.net/problem/1100
//http://1ilsang.blog.me/221414989195

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char tmp;
            scanf(" %c", &tmp);
            if (!(i % 2) && !(j % 2) && tmp == 'F') {
                ans++;
            } else if(i % 2 && j % 2 && tmp == 'F') {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
