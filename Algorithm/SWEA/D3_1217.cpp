//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14dUIaAAUCFAYD&categoryId=AV14dUIaAAUCFAYD&categoryType=CODE

#include <stdio.h>

int go(int n, int m){
    if(m == 1) return n;
    return n * go(n, m - 1);
}

int main(void){
    int t = 10;
    while(t--){
        int cnt, n, m;
        scanf("%d", &cnt);
        scanf("%d %d", &n, &m);
        printf("#%d %d\n", cnt, go(n, m));
    }
    return 0;
}