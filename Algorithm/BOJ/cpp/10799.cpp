//https://www.acmicpc.net/problem/10799
//http://1ilsang.blog.me/221327070400

#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string str;
	stack<char> s;
	cin >> str;
	int ans = 0, flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			flag = 1;
		}
		else if (str[i] == ')') {
			s.pop();
			if (flag == 0) {
				ans++;
			}
			else if (flag == 1) {
				ans += s.size();
				flag = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
