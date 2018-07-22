//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcD_66pUEDFAV8&categoryId=AWNcD_66pUEDFAV8&categoryType=CODE
//http://1ilsang.blog.me/221324172330

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    int tcase;
    scanf("%d", &tcase);
    for(int t = 1; t <= tcase; t++){
        string str;
        cin >> str;
        printf("#%d ", t);
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'a' || str[i] == 'e'  || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') continue;
            printf("%c", str[i]);
        }puts("");
    }
    return 0;
}
