//https://www.acmicpc.net/problem/10448
//http://1ilsang.blog.me/221385724960

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int eureka[50];
vector<int> v;

bool go(int lo, int n) {
	bool ret = false;
	if (v.size() == 3) {
		int tmp = 0;
		for (int i = 0; i < 3; i++) {
			tmp += eureka[v[i]];
		}
		if (tmp == n) ret = true;
		return ret;
	}
	for (int i = 0; i < 45; i++) {
		if (eureka[i] > n) break;
		v.push_back(i);
		ret = max(ret, go(lo + 1, n));
		v.pop_back();
	}
	return ret;
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i < 45; i++) eureka[i - 1] = i*(i + 1) / 2;
	for (int t = 0; t < tcase; t++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", go(0, num));
	}
	return 0;
}
