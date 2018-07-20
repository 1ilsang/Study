//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PsIl6AXIDFAUq&categoryId=AV5PsIl6AXIDFAUq&categoryType=CODE
//http://1ilsang.blog.me/221322718255

#include <stdio.h>

int main(void){
    int tcase;
    scanf("%d", &tcase);
    int check[8] = {50000,10000,5000,1000,500,100,50,10};
    for(int t = 1; t <= tcase; t++){
        int money;
        int ans[8] = {0,};
        scanf("%d", &money);
        for(int i = 0; i < 8; i++){
        	if(money / check[i]) { 
            	ans[i] = money / check[i];
            	money %= check[i];
        	}
        }
        printf("#%d\n", t);
        for(auto i : ans) printf("%d ", i);
        puts("");
    }
    return 0;
}
