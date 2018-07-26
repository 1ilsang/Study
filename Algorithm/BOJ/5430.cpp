//https://www.acmicpc.net/problem/5430

#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	while (tcase--) {
		int n, flag = 0, now = 0;
		char tmp;
		deque<int> dq;
		string cmd;
		char aaa[100005];
		scanf("%s", &aaa);
		//cin >> cmd;
		//remove 'RR'
		cmd = aaa;
		/*for (int i = 0; i < cmd.size(); i++) {
			printf("%c", cmd[i]);
		}puts("");*/
		scanf("%d", &n);
		// 띄우기로 개행문자 처리
		scanf(" %c", &tmp);
		for (int i = 0; i < n; i++) {
			int num;
			scanf(" %d,", &num);
			dq.push_back(num);
		}
		scanf(" %c", &tmp);

		/*for (int i = 0; i < dq.size(); i++) {
			printf("%d", dq[i]);
		}puts("");*/
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') {
				//reverse(v.begin(), v.end());
				now = !now;
			}
			else if (cmd[i] == 'D') {
				if (dq.empty()) {
					flag = 1;
					break;
				}
				if(now == 0)
					dq.pop_front();
				if (now == 1)
					dq.pop_back();
			}
		}
		if (flag == 1) {
			printf("error\n");
			continue;
		}
		printf("[");
		if (dq.empty()) {
			printf("]\n");
			continue;
		}
		if (now == 0) {
			for (int i = 0; i < dq.size() - 1; i++) {
				printf("%d,", dq[i]);
			}
			printf("%d]\n", dq[dq.size() - 1]);
		}
		else if (now == 1) {
			for (int i = dq.size() - 1; i > 0; i--) {
				printf("%d,", dq[i]);
			}
			printf("%d]\n", dq[0]);
		}
	}
	return 0;
}
