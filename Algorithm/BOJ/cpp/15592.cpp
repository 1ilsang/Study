//https://www.acmicpc.net/problem/15592
//http://1ilsang.blog.me/221399978991

#include <cstdio>

int main(void) {
	int rx1, rx2, ry1, ry2;
	int cx1, cx2, cy1, cy2;
	scanf("%d %d %d %d", &rx1, &ry1, &rx2, &ry2);
	scanf("%d %d %d %d", &cx1, &cy1, &cx2, &cy2);
	
	if (ry2 <= cy2 && ry1 >= cy1) {
		if (cx2 >= rx2 && cx1 <= rx1) {
			printf("0\n");
			return 0;
		}
		else if (cx1 < rx2 && cx1 > rx1 && cx2 >= rx2) {
			rx2 = cx1;
		}
		else if (cx1 <= rx1 && cx2 > rx1) {
			rx1 = cx2;
		}
	}
	else if (cx1 <= rx1 && cx2 >= rx2) {
		if (cy1 < ry2 && cy2 >= ry2) {
			ry2 = cy1;
		}
		else if (ry1 >= cy1 && cy2 > ry1) {
			ry1 = cy2;
		}
	}
	int ans = (ry2 - ry1) * (rx2 - rx1);
	ans *= ans < 0 ? -1 : 1;
	printf("%d\n", ans);
	return 0;
}
