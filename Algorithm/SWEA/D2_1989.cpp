//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PyTLqAf4DFAUq&categoryId=AV5PyTLqAf4DFAUq&categoryType=CODE

#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int main(void) {
    int t, cnt = 1;
    scanf("%d", &t);
    while (t--) {
        int ans = 1;
        string s;
        cin >> s;
        for (int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - i - 1]){
                ans = 0;
            }
        }
        printf("#%d %d\n", cnt++, ans);
    }
    return 0;
}