//https://www.acmicpc.net/problem/10828

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
	int n, top = 0;
	int stack[10001];
	string cmd;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> cmd;
		if(cmd == "push") {
			scanf("%d", &num);
			stack[top++] = num;
			}
		if (cmd == "top") {
			if (top == 0) printf("-1\n");
			else printf("%d\n", stack[top - 1]);
		}
		if (cmd == "size") {
			printf("%d\n", top);
		}
		if (cmd == "empty") {
			if (top == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if (cmd == "pop") {
			if (top == 0) printf("-1\n");
			else {
				printf("%d\n", stack[top-1]);
				top--;
			}
		}
	}
	return 0;
}
