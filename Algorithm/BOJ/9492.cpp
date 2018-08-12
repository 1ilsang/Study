//https://www.acmicpc.net/problem/9492
//http://1ilsang.blog.me/221337308897

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int n = 1;
	while (n) {
		vector<string> v;
		vector<string> v2;
		string str;
		scanf("%d", &n);
		int m, k = 0, k2 = 0;
		n % 2 == 0 ? m = n / 2 : m = n / 2 + 1;
		for (int i = 0; i < m; i++) {
			cin >> str;
			v.push_back(str);
		}
		for (int i = 0; i < n - m; i++) {
			cin >> str;
			v2.push_back(str);
		}
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				cout << v[k++] << endl;
			}
			else {
				cout << v2[k2++] << endl;
			}
		}
	}
	return 0;
}
