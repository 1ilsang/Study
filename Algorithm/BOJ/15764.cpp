//https://www.acmicpc.net/problem/15764
//http://1ilsang.blog.me/221395344823

#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int state[101];
int order[101];

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		order[b] = a;
		state[a] = b;
	}
	for (int i = 1; i <= n; i++) {
		if (order[i] != 0) continue;

		int k = 0;
		for (int j = 1; k < v.size() && j <= n; j++) {
			if (v[k] == 1) {
				if (i == j)k++;
				else continue;
			}
			else if (i == j) continue;
			else if (order[j] == v[k]) k++;
			else if (order[j] == 0) {
				if (state[v[k]] == 0) k++;
			}
		}
		if (k == m) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
