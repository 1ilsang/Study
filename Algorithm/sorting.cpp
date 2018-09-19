//각종 정렬 알고리즘 정리(퀵소트, 힙소트, 병합정렬, 버블 소트, 삽입 정렬, 선택 정렬) heap, quick, merge, bubble, insertion, selection
//http://1ilsang.blog.me/221362450863

#include <cstdio>
//rand header
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void bubbleSort(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
			}
			/*printf("%d %d\n", i, j);
			for (int z = 0; z < size; z++) {
				printf(" %d ", arr[z]);
			}puts("");
*/
		}
	}
}

void insertionSort(int * arr, int size) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = arr[i];
		for (; j >= 0 && key < arr[j]; j--) {
			arr[j + 1] = arr[j];

			/*printf("%d %d\n", i, j);
			for (int z = 0; z < size; z++) {
				printf(" %d ", arr[z]);
			}puts("");*/

		}
		arr[j + 1] = key;
	}
}

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minKey = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[minKey] > arr[j]) minKey = j;
		}
		if(minKey != i) swap(arr, i, minKey);

		//printf("%d \n", i);
		//for (int z = 0; z < size; z++) {
		//	printf(" %d ", arr[z]);
		//}puts("");

	}
}

int mergeArr[10];
void mergeSort(int arr[], int size, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, size, left, mid);
		mergeSort(arr, size, mid + 1, right);
		int l = left;
		int r = mid + 1;
		int k = left;
		while (l <= mid && r <= right) {
			if (arr[l] < arr[r]) mergeArr[k++] = arr[l++];
			else mergeArr[k++] = arr[r++];
		}
		if (l > mid) {
			for (int z = r; z <= right; z++) {
				mergeArr[k++] = arr[z];
			}
		}
		else {
			for (int z = l; z <= mid; z++) {
				mergeArr[k++] = arr[z];
			}
		}
		for (int z = left; z <= right; z++) {
			arr[z] = mergeArr[z];
		}
	}
}

void quickSort(int arr[], int size, int left, int right) {
	if (right <= left) return;
	int L = left;
	int R = right + 1;
	int pivot = left + rand() % (right - left + 1);

	swap(arr, left, pivot);
	while (L < R) {
		do { L++; } while (L <= right && arr[left] > arr[L]);
		do { R--; } while (R > left && arr[left] < arr[R]);
		if (L < R) swap(arr, L, R);
	}
	swap(arr, R, left);

	//printf("pivot: %d\n", arr[r]);
	//for (int i = 0; i < size; i++) {
	//   printf(" %d", arr[i]);
	//}puts("");

	quickSort(arr, size, left, R - 1);
	quickSort(arr, size, R + 1, right);
}

class Heap {
private:
	int arr[100000];
	int size;
public:
	Heap() {
		size = 0;
		arr[100000] = { 0, };
	}
	void push(int num) {
		arr[++size] = num;
		int idx = size;
		while (idx > 1) {
			if (arr[idx / 2] > arr[idx]) {
				int tmp = arr[idx];
				arr[idx] = arr[idx / 2];
				arr[idx / 2] = tmp;
				idx /= 2;
			}
			else return;
		}
	}
	int pop(void) {
		if (size == 0) return -1;
		int ret = arr[1];
		arr[1] = arr[size];
		arr[size--] = 0;
		int idx = 1;
		while (idx <= size) {
			int next = idx;
			if (idx * 2 <= size && arr[idx * 2] < arr[idx]) next = idx * 2;
			if (idx * 2 + 1 <= size && arr[idx * 2 + 1] < arr[next]) next = idx * 2 + 1;
			if (idx == next) break;
			int tmp = arr[next];
			arr[next] = arr[idx];
			arr[idx] = tmp;
			idx = next;
		}
		return ret;
	}
};

int main(void) {
	int arr[] = { 2, 6, 1, 3, 2, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Heap h;
	srand(time(NULL));

	//bubbleSort(arr, size);
	//insertionSort(arr, size);
	//selectionSort(arr, size);
	//mergeSort(arr, size, 0, size - 1);
	//quickSort(arr, size, 0, size - 1);
	printf("\nARR:");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}puts("");
	//HeapSort
	for (int i = 0; i < size; i++) {
		h.push(arr[i]);
	}
	for (int i = 0; i < 6; i++) {
		printf(" %d", h.pop());
	}puts("");
	return 0;
}
