//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE
//http://1ilsang.blog.me/221314174263

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int mons[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void){
    int t, cnt = 1;
    scanf("%d", &t);
    while(t--){
        int year, month, day, flag = 0;
        scanf("%4d", &year);
        scanf("%2d", &month);
        scanf("%2d", &day);
        
        for(int i = 1; i<13;i++){
            if(i == month){
                if(0 < day && day <= mons[i]){
                    flag = 1;
                    break;
                }
            }
        }
        
        if(flag){
            string y = "", m = "" , d = "";
            if(year < 1000) y = "0";
            if(month < 10) m = "0";
            if(day < 10) d = "0";
            
            printf("#%d %s%d/%s%d/%s%d\n", cnt++, y.c_str(), year, m.c_str(), month, d.c_str(), day);
        }else {
            printf("#%d -1\n", cnt++);
        }
    }
    return 0;
}
