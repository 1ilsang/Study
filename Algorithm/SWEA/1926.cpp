//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE
//http://1ilsang.blog.me/221318678834

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
        int check = i, flag = 0;
		while (check) {
            if(check % 10 == 3 || check % 10 == 6 || check % 10 == 9){
                flag = 1;
				printf("-");
            }
			check /= 10;
		}
        if(flag == 0) {
            printf("%d ", i);
        }else {
            printf(" ");
        }
	}
	return 0;
}
