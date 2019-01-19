//https://www.acmicpc.net/problem/3671
//http://1ilsang.blog.me/221366753276

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v, list;
const int MAX = 10000002;
bool era[MAX];
bool chk[8];
bool chkNum[MAX];
int ans;

int myPow(int n) {
	if (n == 0) return 1;
	int tmp = myPow(n / 2);
	int ret = tmp*tmp;
	if (n % 2) ret *= 10;
	return ret;
}

void go(int lo) {
	if (lo > 0) {
		int num = 0;
		for (int i = 0; i < list.size(); i++) {
			num += v[list[i]] * myPow(list.size() - i - 1);
		}
		if (era[num] == false && chkNum[num] == false) {
			chkNum[num] = true;
			ans++;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			list.push_back(i);
			go(lo + 1);
			chk[i] = 0;
			list.pop_back();
		}
	}
}

void getEratos() {
	era[0] = era[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (era[i] == false) {
			for (int j = i + i; j < MAX; j += i) {
				era[j] = true;
			}
		}
	}
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	getEratos();
	for (int t = 0; t < tcase; t++) {
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			v.push_back(str[i] - 48);
		}
		go(0);
		printf("%d\n", ans);
		memset(chk, 0, sizeof(chk));
		memset(chkNum, 0, sizeof(chkNum));
		v.clear();
		ans = 0;
	}
	return 0;
}
