//https://www.acmicpc.net/problem/3671
//http://1ilsang.blog.me/221366753276

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v, chk, ord;
int ans;
const int MAX = 10000001;
bool era[MAX];
int chkNum[MAX];

void getEratosthenes() {
	era[0] = era[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (era[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				era[j] = true;
			}
		}
	}
}

int myPow(int n) {
	if (n == 0) return 1;
	int tmp = myPow(n / 2);
	int ret = tmp * tmp;
	if (n % 2) ret *= 10;
	return ret;
}

void go(int lo) {
	if (lo > 0) {
		int num = 0;
		for (int i = 0; i < ord.size(); i++) {
			num += v[ord[i]] * myPow(ord.size() - i - 1);
		}
		if (chkNum[num] == 0) {
			chkNum[num] = 1;
			if (era[num] == false) ans++;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			ord.push_back(i);
			go(lo + 1);
			chk[i] = 0;
			ord.pop_back();
		}
	}
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	getEratosthenes();
	for (int t = 0; t < tcase; t++) {
		string str;
		cin >> str;
		chk.resize(str.size());

		for (int i = 0; i < str.size(); i++) {
			v.push_back(str[i] - 48);
		}

		go(0);
		printf("%d\n", ans);

		ans = 0;
		v.clear();
		chk.clear();
		ord.clear();
		memset(chkNum, 0, sizeof(chkNum));
	}
	return 0;
}
