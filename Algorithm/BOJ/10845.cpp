//https://www.acmicpc.net/problem/10845

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int q[10001];
		int size = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			scanf("%d", &num);
			q[size++] = num;
		}
		else if (s == "front") {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[0]);
			}
		}
		else if (s == "back") {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[size - 1]);
			}
		}
		else if (s == "size") {
			printf("%d\n", size);
		}
		else if (s == "empty") {
			if (size == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (s == "pop") {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				int front = q[0];
				for (int i = 0; i < size - 1; i++) {
					q[i] = q[i + 1];
				}
				q[size - 1] = NULL;
				size--;
				printf("%d\n", front);
			}
		}
	}
}
