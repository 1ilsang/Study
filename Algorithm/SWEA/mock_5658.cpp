//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
//

#include <cstdio>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v;
deque<int> dq;
int n, k, tcase;

bool cmp(int a, int b) {
	return a > b;
}

int myPow(int x, int n) {
	if (n == 0) return 1;
	int tmp = myPow(x, n / 2);
	int ret = tmp * tmp;
	if (n % 2) ret *= x;
	return ret;
}

int main(void) {
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			char tmp;
			scanf(" %C", &tmp);
			if (tmp < 'A') dq.push_back(tmp - 48);
			else dq.push_back(tmp - 55);
		}
		for (int z = 0; z < n; z++) {
			int slice = n / 4;
			int num = 0;
			for (int i = 0; i < n; i++) {
				num += myPow(16, slice - 1) * dq[i];
				slice--;
				if (slice == 0) {
					slice = n / 4;
					v.push_back(num);
					num = 0;
				}
			}
			int back = dq.back();
			dq.push_front(back);
			dq.pop_back();
		}
		sort(v.begin(), v.end(), cmp);
		v.erase(unique(v.begin(), v.end()), v.end());
		printf("#%d %d\n", t, v[k - 1]);
		v.clear();
		dq.clear();
	}
	return 0;
}
