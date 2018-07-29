//https://www.acmicpc.net/problem/11970
//http://1ilsang.blog.me/221328922544

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int check[27];
int l, c;

void go(int now, int lo, int mo, int ja) {
	if (lo == l+ 1 && ja > 1 && mo > 0) {
		for (int i = 0; i < 27; i++) {
			if(check[i] == 1)
				printf("%c", i + 'a');
		}puts("");
		return;
	}
	for (int i = now; i <v.size(); i++) {
		if (check[v[i]] == 0) {
			check[v[i]] = 1;
			if (v[i] == 0 || v[i] == 4 || v[i] == 8 || v[i] == 14 || v[i] == 20) go(i, lo + 1, mo + 1, ja);
			else go(i, lo + 1, mo, ja + 1);
			check[v[i]] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		char num;
		scanf(" %c", &num);
		v.push_back(num - 'a');
	}
	sort(v.begin(), v.end());
	go(0, 1, 0, 0);
	return 0;
}
