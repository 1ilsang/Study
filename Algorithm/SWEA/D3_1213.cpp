//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14P0c6AAUCFAYi&categoryId=AV14P0c6AAUCFAYi&categoryType=CODE
//http://1ilsang.blog.me/221323675039

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void){
    for(int tcase = 1; tcase <= 10; tcase++){
        int tmp, ans = 0;
        scanf("%d", &tmp);
        string a;
        string b;
        cin >> a;
        cin >> b;
        for(int i = 0; i < b.size(); i++){
                int k = i, cnt = 0;
            for(int j = 0; j < a.size(); j++){
                if(b[k] == a[j]){
                    k++;
                    cnt++;
                    //printf(" %c %d %c %d\n", b[k],k, a[j], cnt);
                    if(cnt == a.size()){
                        ans++;
                    }
                }
                else {
                    break;}
            }
        }
        printf("#%d %d\n", tcase, ans);
    }
    return 0;
}
