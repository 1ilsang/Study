//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QPsXKA2UDFAUq&categoryId=AV5QPsXKA2UDFAUq&categoryType=CODE

#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

vector<int> v;

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    printf("%d\n", v[n/2]);
    return 0;
}