//https://www.acmicpc.net/problem/10866
//http://1ilsang.blog.me/221325437003

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
	int n, size = 0;
	int deque[10001] = { 0, };
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_back") {
			int num;
			scanf("%d", &num);
			deque[size++] = num;
		}
		else if (cmd == "push_front") {
			int num;
			scanf("%d", &num);
			for (int i = size; i > 0; i--) {
				deque[i] = deque[i - 1];
			}
			deque[0] = num;
			size++;
		}
		else if (cmd == "pop_front") {
			if (size == 0) {
				printf("-1\n");
				continue;
			}
			else {
				printf("%d\n", deque[0]);
				for (int i = 0; i < size - 1; i++) {
					deque[i] = deque[i + 1];
				}
				deque[size - 1] = 0;
				size--;
			}
		}
		else if (cmd == "pop_back") {
			if (size == 0) printf("-1\n");
			else {
				printf("%d\n", deque[size - 1]);
				deque[size - 1] = 0;
				size--;
			}
		}
		else if (cmd == "size") {
			printf("%d\n", size);
		}
		else if (cmd == "empty") {
			if (size == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (cmd == "front") {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deque[0]);
			}
		}
		else if (cmd == "back") {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deque[size - 1]);
			}
		}
	}
	return 0;
}
