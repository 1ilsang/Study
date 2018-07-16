//https://www.acmicpc.net/problem/10815
//http://1ilsang.blog.me/221320252753

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int go(int n, int l, int r) {
	int mid = (l + r) / 2;
	int ret = 0;
//	printf("%d %d %d %d\n", l, r, mid, v[mid]);
	if (l > r) return ret;
	if (n == v[mid]) {
		ret = 1;
		return ret;
	}
	else if (n < v[mid]) {
		ret = go(n, l, mid - 1);
	}
	else if (n > v[mid]) {
		ret = go(n, mid + 1, r);
	}
	else {
		return ret;
	}
	return ret;
}

int main(void) {
	int n, m, p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d ", go(tmp, 0, v.size() - 1));
	}
	return 0;
}
