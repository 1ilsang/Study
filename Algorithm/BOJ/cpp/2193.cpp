//https://www.acmicpc.net/problem/2193
//http://1ilsang.blog.me/221339347713

#include <iostream>
using namespace std;
long long d[91];
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i-2];
	}
	cout << d[n] << endl;
	return 0;
}
