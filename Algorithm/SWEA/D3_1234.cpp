//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14_DEKAJcCFAYD&categoryId=AV14_DEKAJcCFAYD&categoryType=CODE
//http://1ilsang.blog.me/221316138373

#include <stdio.h>
#include <stack>
using namespace std;

int main(void){
    for(int tcase = 1; tcase < 11; tcase++){
        int n, tmp;
        stack<int> s, t;
        scanf("%d", &n);
        scanf("%1d", &tmp);
        s.push(tmp);
        for(int i = 1; i < n; i++){
            scanf("%1d", &tmp);
            if(!s.empty() && s.top() == tmp){
                s.pop();
            } else {
                s.push(tmp);
            }
        }
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        printf("#%d ", tcase);
        while(!t.empty()){
            printf("%d", t.top());
            t.pop();
        }puts("");
    }
    return 0;
}
