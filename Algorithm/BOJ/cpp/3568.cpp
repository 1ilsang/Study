//https://www.acmicpc.net/problem/3568
//http://1ilsang.blog.me/221436875424

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    string str;
    string strt = "";
    string tmp = "";
    string value = "";
    int flag = 1;

    getline(cin, str);
    for(int i =0; i < str.size(); i++) {
        if(str[i] == ' ' && flag){
            strt = tmp;
            tmp = "";
            flag = 0;
        }
        else if(str[i] == ',' || str[i] == ';'){
            cout << strt;
            for(int j = tmp.size() - 1; j >=0;j--) {
                if(tmp[j] == '[') printf("]");
                else if(tmp[j] == ']') printf("[");
                else printf("%c", tmp[j]);
            }
            cout << " " << value << ';' << endl;
            value = "";
            tmp = "";
        }
        else if(!flag && ((str[i] <= 'z' && str[i] >= 'a') || ('A' <= str[i] && str[i] <= 'Z'))){
            value += str[i];
        }
        else if(str[i] != ' '){
            tmp += str[i];
        }
    }
    return 0;
}
