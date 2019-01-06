//https://www.acmicpc.net/problem/10809
//http://1ilsang.blog.me/221435545943

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int chk[27];
    memset(chk, -1, sizeof(chk));
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (chk[str[i] - 'a'] == -1) chk[str[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++) printf("%d ", chk[i]);
    puts("");
    return 0;
}
