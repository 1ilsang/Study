//http://1ilsang.blog.me/221360182830

#include <cstdio>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int a, b, c;
};

vector<Node> v;

bool cmp(Node a, Node b) {
	return make_tuple( a.a, -a.b, a.c ) < make_tuple(b.a, -b.b, b.c);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp, tmp2, tmp3;
		scanf("%d %d %d", &tmp, &tmp2, &tmp3);
		v.push_back({ tmp, tmp2, tmp3 });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		printf(" %d %d %d\n", v[i].a, v[i].b, v[i].c);
	}
	return 0;
}
