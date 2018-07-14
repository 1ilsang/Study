//https://www.acmicpc.net/problem/1063
//http://1ilsang.blog.me/221319146808

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b;
	int king[2], stone[2];
	int n;
	cin >> a;
	cin >> b;
	king[0] = a[0] - 'A';
	stone[0] = b[0] - 'A';
	king[1] = a[1] - '1';
	stone[1] = b[1] - '1';
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string move;
		int dc = 0, dr = 0;
		cin >> move;
		for (int i = 0; i < move.size(); i++) {
			if (move[i] == 'T') dr++;
			else if (move[i] == 'R') dc++;
			else if (move[i] == 'L') dc--;
			else if (move[i] == 'B') dr--;
		}
		if (0 <= king[0] + dc  && king[0] + dc < 8 && king[1] + dr < 8 && 0 <= king[1] + dr) {
			if (king[0] + dc == stone[0] && king[1] + dr == stone[1]) {
				if(0 <= stone[0] + dc  && stone[0] + dc < 8 && stone[1] + dr < 8 && 0 <= stone[1] + dr){
					king[0] += dc;
					king[1] += dr;
					stone[0] += dc;
					stone[1] += dr;
				}
			}
			else {
				king[0] += dc;
				king[1] += dr;
			}
		}
	}
	printf("%c%d\n%c%d\n", king[0] + 65, king[1] + 1, stone[0] + 65, stone[1] + 1);
	return 0;
}
