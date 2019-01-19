//https://www.acmicpc.net/problem/3085
//http://1ilsang.blog.me/221385693232

#include <cstdio>
#include <algorithm>
using namespace std;

char area[51][51];
int n;

int chk() {
	int ret = 1, ret2 = 1, ans = 1;
	for (int i = 0; i < n; i++) {
		int tmp = 1, tmp2 = 1;
		for (int j = 0; j < n - 1; j++) {
			if (area[i][j] == area[i][j + 1]) tmp++;
			else ret = max(tmp, ret), tmp = 1;
			if (area[j][i] == area[j + 1][i]) tmp2++;
			else ret2 = max(tmp2, ret2), tmp2 = 1;
		}
		ret = max(tmp, ret);
		ret2 = max(tmp2, ret2);
		ans = max(ret, ret2);
	}
	return ans;
}

int main(void) {
	int ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) scanf(" %C", &area[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(area[i][j], area[i][j + 1]);
			ans = max(ans, chk());
			swap(area[i][j], area[i][j + 1]);
			swap(area[j][i], area[j + 1][i]);
			ans = max(ans, chk());
			swap(area[j][i], area[j + 1][i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
