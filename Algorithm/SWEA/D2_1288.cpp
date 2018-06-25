////https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18_yw6I9MCFAZN&categoryId=AV18_yw6I9MCFAZN&categoryType=CODE

#include <istream>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int ans;
int check[10];
int chk = 0;
int m;

void go(int n, int cnt){
    int tmp = n;
    while(tmp){
        int mod = tmp % 10;
		if (check[mod] == 0) {
			check[mod] = 1;
			chk++;
//			printf("%d %d %d\n", n, mod, cnt);
		}
        tmp /= 10;
    }
    if(chk == 10){
        ans = cnt + 1;
        return;
    }
    else {
        go(m * (cnt + 2), cnt + 1);
    }
}

int main(void) {
    int t, cnt = 1;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &m);
        go(m, 0);
        printf("#%d %d\n", cnt++, ans * m);
		memset(check, 0, sizeof(check));
		chk = 0;
    }
    return 0;
}