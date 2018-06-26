//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE

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
        string str, tmp = "";
        int j = 0;
        cin >> str;

        for (int i = 1; i < str.size(); ++i) {
            if(str[i] == str[j]){
                j++;
            }else {
                j=0;
            }
        }

        printf("#%d %d\n", cnt++, (int)str.size() - j);
    }
    return 0;
}