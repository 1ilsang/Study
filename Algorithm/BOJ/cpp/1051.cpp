//https://www.acmicpc.net/problem/1051

#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[51][51];

int main(void) {
	int n, m, ans = 1;
	scanf("%d %d", &n, &m);
	int minr = min(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < minr; k++) {
				//printf("%d %d %d %d\n", i, j, k, minr);
				if (i + k >= n || j + k >= m) continue;
				if(arr[i][j] == arr[i][j + k] && arr[i + k][j] == arr[i][j] &&
					arr[i][j] == arr[i + k][j + k]){
					ans = max(ans, (k+1) * (k + 1));
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
