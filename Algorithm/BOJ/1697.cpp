//https://www.acmicpc.net/problem/1697
//

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, k, ans = 99999999;
int check[100001];
queue<pair<int, int>> q;

void bfs(int n, int lo) {
	q.push({ n,lo });
	while (!q.empty()) {
		int now = q.front().first;
		int lo = q.front().second;
		q.pop();
		if (now == k) {
			ans = lo;
			break;
		}
		check[now] = 1;
		if (now - 1 >= 0 && check[now - 1] == 0) {
			q.push({ now - 1,lo + 1 });
		}
		if (now + 1 <= 100000 && check[now + 1] == 0) {
			q.push({ now + 1, lo + 1 });
		}
		if (now * 2 <= 100000 && check[now * 2] == 0) {
			q.push({ now * 2 , lo + 1 });
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &k);
	bfs(n, 0);
	printf("%d\n", ans);
	return 0;
}
