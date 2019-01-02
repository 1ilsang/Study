//https://www.acmicpc.net/problem/4889
//http://1ilsang.blog.me/221432281688

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    int t = 1;
    while (true) {
        stack<int> stk;
        int ans = 0;
        string str;
        cin >> str;
        if (str[0] == '-') break;

        for (int i = 0; i < str.size(); i++) {
            if(stk.empty()) stk.push(str[i]);
            else {
                int top = stk.top();
                if(top == '{' && str[i] == '}') stk.pop();
                else stk.push(str[i]);
            }
        }
        str = "";
        while(!stk.empty()) str += (char)stk.top(), stk.pop();

        for(int i = 1; i < str.size(); i += 2) {
            if(str[i - 1] == '{' && str[i] == '}') ans += 2;
            else ans++;
        }
        printf("%d. %d\n", t++, ans);
    }
    return 0;
}
