//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PttaaAZIDFAUq&categoryId=AV5PttaaAZIDFAUq&categoryType=CODE

#include <stdio.h>

int main(void) {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		int h1, m1, h2, m2, ansH, ansM;
		scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
		ansM = (m1 + m2) % 60;
		ansH = ((h1 + h2) + (m1 + m2) / 60) % 12;
        if(ansH == 0) ansH = 12;
		printf("#%d %d %d\n", cnt++, ansH, ansM);
	}
	return 0;
}
