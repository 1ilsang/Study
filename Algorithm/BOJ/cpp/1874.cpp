//https://www.acmicpc.net/problem/1874
//http://1ilsang.blog.me/221321379852

#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<int> v;

int main(void) {
	int n, k = 1, flag = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		while (k <= n + 1) {
			if (!s.empty() && s.top() == tmp) {
				s.pop();
				v.push_back(0);
				break;
			}
			else {
				s.push(k++);
				v.push_back(1);
			}
		}
	}
	if (!s.empty()) printf("NO\n");
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				printf("-\n");
			}
			else {
				printf("+\n");
			}
		}
	}
	return 0;
}
