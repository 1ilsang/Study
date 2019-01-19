//http://1ilsang.blog.me/221332542362
//https://www.acmicpc.net/problem/10708

#include <cstdio>
#include <vector>
using namespace std;

vector<int> v, ans, target;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n);
	ans.resize(n);
	target.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &target[i]);
	}
	for(int k = 0; k < m; k++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		for (int i = 0; i < n; i++) {
			if (v[i] == target[k]) {
				ans[i]++;
			}
			else {
				ans[target[k] - 1]++;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
