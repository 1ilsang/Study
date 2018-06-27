//
// Created by user on 2018. 6. 27..
//

//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int t, cnt = 1;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        string s;
        cin >> s;

        if(s[0] - '0' == 1) ans++;

        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                continue;
            } else {
                ans++;
            }
        }

        printf("#%d %d\n", cnt++, ans);
    }
    return 0;
}