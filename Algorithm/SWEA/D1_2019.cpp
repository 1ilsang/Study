#include <stdio.h>

int main(void){
    int n, ans = 1;
    scanf("%d", &n);
    for(int i = 0; i<=n;i++){
        printf("%d ", ans);
        ans *= 2;
    }
    return 0;
}