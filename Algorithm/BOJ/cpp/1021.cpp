//https://www.acmicpc.net/problem/1021

#include <cstdio>
#include <algorithm>
using namespace std;

int arr[51];
int main(void) {
	int n, m, now = 0, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int target, next;
		scanf("%d", &target);
		target -= 1;
		if (now == target) {
			arr[now] = 1;
		}
		else {
			int lCnt = 0, rCnt = 0, rFlag = 0, lFlag = 0;
			for (int j = 1; j < n; j++) {
				if (rFlag == 1 && lFlag == 1) break;
				int nextR = (now + j) % n;
				int nextL = abs((n + (now - j)) % n);
				if (arr[nextR] == 0 && rFlag == 0) {
					rCnt++;
					if (nextR == target) {
						rFlag = 1;
					}
				}
				if (arr[nextL] == 0 && lFlag == 0) {
					lCnt++;
					if (nextL == target) {
						lFlag = 1;
					}
				}
				//printf(" t: %d, next:: %d %d, Cnt: %d %d\n", target, nextL, nextR, lCnt, rCnt);
			}
			arr[target] = 1;
			if (lCnt < rCnt) {
				ans += lCnt;
			}
			else {
				ans += rCnt;
			}
		}
		next = target;
		int maxN = 0;
		while (arr[next] == 1) {
			next++;
			maxN++;
			if (next >= n) next = 0;
			if (maxN == n)break;
		}
		now = next;
		//printf(" %d %d %d\n", target, now, ans);
	}
	printf("%d\n", ans);
	return 0;
}
