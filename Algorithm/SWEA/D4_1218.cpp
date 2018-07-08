//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14eWb6AAkCFAYD&categoryId=AV14eWb6AAkCFAYD&categoryType=CODE
//http://1ilsang.blog.me/221315092200

#include <stdio.h>
#include <stack>
using namespace std;

int main(void){
    int t = 10, cnt = 1;
    while(t--){
        stack<int> s;
        int n, flag = 0;
        char tmp[5000];
        scanf("%d", &n);
        scanf("%s", &tmp);
        for(int i = 0; i< n; i++){
            if(tmp[i] == '(' || tmp[i] == '[' || tmp[i] == '{' || tmp[i] == '<'){
                s.push(tmp[i]);
            } else {
                if(s.empty()){
                    flag = 1;
                    break;
                } else {
                    if(s.top() / 10 == tmp[i] / 10){
                        s.pop();
                    } else {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag){
            printf("#%d 0\n", cnt++);
        }else {
            printf("#%d 1\n", cnt++);
        }
    }
    return 0;
}
