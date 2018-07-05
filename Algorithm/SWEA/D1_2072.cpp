//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QSEhaA5sDFAUq&categoryId=AV5QSEhaA5sDFAUq&categoryType=CODE

#include <stdio.h>

int main(void){
    int t, cnt = 1;
    scanf("%d", &t);
    while(t--){
        int ans = 0;
        for(int i = 0; i< 10; i++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp % 2 == 1){
                ans += tmp;
            }
        }
        printf("#%d %d\n", cnt++, ans);
    }
    return 0;
}