//https://www.acmicpc.net/problem/5397

#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {
		string str;
		cin >> str;
		stack<char> ans, ansReverse;
		stack<char> tmp;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (ans.empty()) continue;
				else {
					tmp.push(ans.top());
					ans.pop();
				}
			}
			else if (str[i] == '>') {
				if (tmp.empty()) continue;
				else {
					ans.push(tmp.top());
					tmp.pop();
				}
			}
			else if (str[i] == '-') {
				if (ans.empty()) continue;
				else {
					ans.pop();
				}
			}
			else {
				ans.push(str[i]);
			}
		}
		while (!tmp.empty()) {
			ans.push(tmp.top());
			tmp.pop();
		}
		while (!ans.empty()) {
			ansReverse.push(ans.top());
			ans.pop();
		}
		while (!ansReverse.empty()) {
			printf("%c", ansReverse.top());
			ansReverse.pop();
		}puts("");
	}
	return 0;
}
