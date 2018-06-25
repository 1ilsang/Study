//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV189xUaI8UCFAZN&categoryId=AV189xUaI8UCFAZN&categoryType=CODE

#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int t, cnt = 1;
    scanf("%d", &t);

    while (t--) {
        int p,q,r,s,w, A, B;
        scanf("%d %d %d %d %d", &p, &q, &r, &s, &w);

        A = p * w;
        if(r >= w) {
            B = q;
        }
        else {
            B = q + (w-r) * s;
        }
        printf("#%d %d\n", cnt++, A < B ? A : B);
    }
    return 0;
}