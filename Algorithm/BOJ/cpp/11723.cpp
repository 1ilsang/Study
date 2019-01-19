//https://www.acmicpc.net/problem/11723
//http://1ilsang.blog.me/221446095017

#include <cstdio>
#include <string>

using namespace std;

int main(void) {
    int t;
    int bit = 0;
    string cmd;
    scanf("%d", &t);

    while (t--) {
        int tmp = 0, n;
        char str[50];
        scanf("%s", str);
        cmd = str;
        if (cmd == "all") bit = (1 << 21) - 1;
        else scanf(" %d", &n);

        if (cmd == "add") bit |= (1 << (n - 1));
        else if (cmd == "remove") bit &= ~(tmp | 1 << (n - 1));
        else if (cmd == "check") (bit & (1 << (n - 1))) ? puts("1") :puts("0");
        else if (cmd == "toggle") bit = bit ^ (1 << (n - 1));
        else if (cmd == "empty") bit = 1 >> 21;
    }
    return 0;
}
