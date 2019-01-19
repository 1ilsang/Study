//https://www.acmicpc.net/problem/1927
//http://1ilsang.blog.me/221357652296

#include <cstdio>

int n;

class heap {
private:
	int size = 0;
	int top;
	int arr[100002] = { 0, };
public:
	int pop() {
		if (size == 0) return 0;
		
		int ret = arr[1];
		int idx = 1;

		arr[1] = arr[size];
		arr[size--] = 0;

		while (idx <= size) {
			int tmp = arr[idx];
			int next = idx;
			if (idx * 2 <= size && arr[idx] > arr[idx * 2]) next = idx * 2;
			if (idx * 2 + 1 <= size && arr[next] > arr[idx * 2 + 1]) next = idx * 2 + 1;
			if (idx == next) break;
			arr[idx] = arr[next];
			arr[next] = tmp;
			idx = next;
		}
		return ret;
	}
	void print() {
		for (int i = 0; i < 10; i++) {
			printf(" %d", arr[i]);
		}puts("");
	}
	void push(int num) {
		arr[++size] = num;
		int idx = size;
		while (idx != 1) {
			if (arr[idx] >= arr[idx / 2]) break;
			else if (arr[idx] < arr[idx / 2]) {
				int tmp = arr[idx];
				arr[idx] = arr[idx / 2];
				arr[idx / 2] = tmp;
				idx /= 2;
			}
		}
	}
};

int main(void) {
	heap h;
	int cmd;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		if (cmd == 0) {
			printf("%d\n", h.pop());
		}
		//else if(cmd == 9) h.print();
		else {
			h.push(cmd);
		}
	}
	return 0;
}
