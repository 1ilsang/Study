//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18-stqI8oCFAZN&categoryId=AV18-stqI8oCFAZN&categoryType=CODE

#include <stdio.h>
#include <algorithm>

int main(void) {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		int n, minLength = 99999999, count = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (abs(tmp) < minLength) {
				minLength = abs(tmp);
				count = 1;
			}
			else if (abs(tmp) == minLength) count++;
		}
		printf("#%d %d %d\n", cnt++, minLength, count);
	}
	return 0;
}
