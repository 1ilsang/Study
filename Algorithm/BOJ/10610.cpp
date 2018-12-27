//https://www.acmicpc.net/problem/10610
//http://1ilsang.blog.me/221428097005

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string arr;
int digit[10];
int t, ans;

int main(void) {
    cin >> arr;

    for (int i = 0; i < arr.size(); ++i) {
        t = arr[i] - '0';
        digit[t]++;
        ans += t % 3;
    }

    if (digit[0] != 0 && ans % 3 == 0) {
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < digit[i]; ++j) {
                printf("%d", i);
            }
        }
        puts("");
    } else {
        printf("-1\n");
    }

    return 0;
}
