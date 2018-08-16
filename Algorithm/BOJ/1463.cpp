//https://www.acmicpc.net/problem/1463
//

#include <iostream>
using namespace std;
int d[1000001];
int dp(int n) {
	if (n == 1)return 0;
	if (d[n] > 0) return d[n];
	d[n] = dp(n - 1) + 1;
	if (n % 2 == 0) {
		int tmp = dp(n/2) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	if (n % 3 == 0) {
		int tmp = dp(n / 3) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	return d[n];
}
int main() {
	int n;
	cin >> n;
	cout << dp(n) << endl;
	return 0;
}
