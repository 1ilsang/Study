//https://www.acmicpc.net/problem/2455

#include <cstdio>

int main(void){
    int n ,m, ans, tmp;
    ans = tmp = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d %d", &n, &m);
        tmp -= n;
        tmp += m;
        if(ans < tmp) ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
