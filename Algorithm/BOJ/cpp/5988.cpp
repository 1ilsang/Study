//https://www.acmicpc.net/problem/5988
//http://1ilsang.blog.me/221366576269

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		if (tmp[tmp.size() - 1] % 2 == 0) printf("even\n");
		else printf("odd\n");
	}
	return 0;
}
