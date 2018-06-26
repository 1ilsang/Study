//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpoFaAS4DFAUq&categoryId=AV5PpoFaAS4DFAUq&categoryType=CODE

#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

vector<int> a, b;

int main(void) {
    int t, cnt = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, max = 0, ans = 0;
        scanf("%d %d", &n, &m);
        a.resize(n);
        b.resize(m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        if (n < m) {
            for (int i = 0; i <= b.size() - a.size(); i++) {
                for (int j = 0; j < a.size(); j++) {
                    ans += a[j] * b[j + i];
                }
                if(ans > max){
                    max = ans;
                }
                ans = 0;
            }
        } else {
            for (int i = 0; i <= a.size() - b.size(); i++) {
                for (int j = 0; j < b.size(); j++) {
                    ans += a[j + i] * b[j];
                }
                if(ans > max){
                    max = ans;
                }
                ans = 0;
            }
        }

        printf("#%d %d\n", cnt++, max);
        a.clear();
        b.clear();
    }
    return 0;
}