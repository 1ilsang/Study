//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18R8FKIvoCFAZN&categoryId=AV18R8FKIvoCFAZN&categoryType=CODE
//http://1ilsang.blog.me/221315772369

#include <stdio.h>

int main(void){
    int tcase;
    scanf("%d", &tcase);
    for(int t = 1; t <= tcase; t++){
        int n, p;
        long long max = 1;
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p-(n%p); i++)
            max *= (n/p);
        for (int i = 0; i < n%p; i++)
            max *= ((n / p)+1);
        printf("#%d %lld\n", t, max);
    }
    return 0;
}
