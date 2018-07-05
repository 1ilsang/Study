//https://www.acmicpc.net/problem/11053

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1010];
int dp[1010];

int main(void) {
	int n, ans = 0;
	scanf("%d", &n);
	scanf("%d", &arr[0]);
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		int tmp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (tmp < dp[j]) {
					tmp = dp[j];
				}
				dp[i] = tmp + 1;
				//printf("%d %d %d\n", arr[i], arr[j], dp[i]);
				if (dp[i] > ans) {
					ans = dp[i];
				}
			}
			else {
				dp[i] = max(dp[i], 1);
			}
		}
	}
	if (ans == 0) {
		ans = 1;
	}
	/*for (int i = 0; i < n; i++) {
		printf("%d ", dp[i]);
	}puts("");*/
	printf("%d\n", ans);
	return 0;
}