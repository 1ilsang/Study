//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QRnJqA5cDFAUq&categoryId=AV5QRnJqA5cDFAUq&categoryType=CODE

#include <stdio.h>

int main(void){
    int t, cnt = 1;
    scanf("%d", &t);
    while(t--){
        int n = 10, ans = 0;
        for(int i = 0; i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            ans += tmp;
        }
        if(((double)ans / (double)n) - ans/n >= 0.5){
            ans = ans/n + 1;
        }else{
            ans = ans / n;
        }
        printf("#%d %d\n", cnt++, ans);
    }
    return 0;
}
