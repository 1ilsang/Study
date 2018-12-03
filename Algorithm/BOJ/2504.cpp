//https://www.acmicpc.net/problem/2504
//http://1ilsang.blog.me/221411630005

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <stack>
 
using namespace std;
 
int main(void) {
    stack<int> stk;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (stk.empty()) {
            if(str[i] == ')' || str[i] == ']') {
                puts("0");
                return 0;
            }
            stk.push(str[i]);
        } else {
            if (str[i] == '(' || str[i] == '[') {
                stk.push(str[i]);
            } else if (str[i] == ')') {
                int tmp = 0;
                while(true) {
                    if(stk.empty() || stk.top() == '[') {
                        puts("0");
                        return 0;
                    } else if(stk.top() == '(') {
                        stk.pop();
                        if(tmp == 0) stk.push('2');
                        else stk.push(tmp * 2 + '0');
                        break;
                    } else {
                        tmp += (stk.top() - '0');
                        stk.pop();
                    }
                }
            } else if (str[i] == ']') {
                int tmp = 0;
                while(true) {
                    if(stk.empty() || stk.top() == '(') {
                        puts("0");
                        return 0;
                    } else if(stk.top() == '[') {
                        stk.pop();
                        if(tmp == 0) stk.push('3');
                        else stk.push((tmp * 3) + '0');
                        break;
                    } else {
                        tmp += (stk.top() - '0');
                        stk.pop();
                    }
                }
            }
        }
    }
    while(!stk.empty()) {
        if(stk.top() == '(' || stk.top() == ')' || stk.top() == '[' || stk.top() == ']') {
            ans = 0;
            break;
        }
        ans += (stk.top() - '0');
        stk.pop();
    }
    printf("%d\n", ans);
    return 0;
}
