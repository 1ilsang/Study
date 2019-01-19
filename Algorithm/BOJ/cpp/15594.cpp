//https://www.acmicpc.net/problem/15594
//http://1ilsang.blog.me/221399971019

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int chk[1000003];

int main(void) {
	int ans = 0;
	int n;
	scanf("%d", &n);
	vector<int> v, v2;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v.size(); i++) {
		if (chk[v[i]] == 0 && v[i] != v2[i]) {
			chk[v[i]] = 1;
			ans++;
		}
	}
	printf("%d\n", ans - 1);
	return 0;
}
