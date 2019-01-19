//https://www.acmicpc.net/problem/11721

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	int i = 0;
	cin >> str;
	while (i < str.size()) {
		if ((i + 1) % 10 == 0) {
			cout << str[i] << '\n';
		}
		else {
			cout << str[i];
		}
		i++;
	}
	return 0;
}
