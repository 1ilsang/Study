// 단방향 연결리스트 추가-삭제-뒤집기
//

#include <stdio.h>
#include <cstdlib>
/*
 * @blog 1ilsang.blog.me
  * @Author 1ilsang
 */
struct Node {
	int data;
	Node* next;
};

Node * Head;

void Linsert(Node* node, int data) {
	while (node->next != NULL) {
		node = node->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	node->next = newNode;
	newNode->next = NULL;
	newNode->data = data;
}

void reverse(Node * node) {
	if (node->next->next != NULL) {
		Head = node->next->next;
		reverse(node->next);
	}
	node->next->next = node;
	node->next = NULL;
}

void printLinked(Node* Head) {
	printf(":: Print %d::\n", &Head);
	while (Head != NULL) {
		printf(" %d", Head->data);
		Head = Head->next;
	}
	printf("\n\n");
}

int deleteNode(Node * node, int data) {
	int ret = 0;
	if (node->data == data) return 1;
	if (node->data != data && node->next != NULL) {
		ret = deleteNode(node->next, data);
	}
	if (ret == 1) {
		Node * tmp = node->next;
		node->next = node->next->next;
		free(tmp);
		return 0;
	}
	return 0;
}

int main() {
	Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	Head->data = 0;
	Linsert(Head, 1);
	Linsert(Head, 2);
	Linsert(Head, 3);
	Linsert(Head, 4);
	Linsert(Head, 5);
	printLinked(Head);
	reverse(Head);
	printLinked(Head);
	printf("delete %d\n", 2);
	deleteNode(Head, 2);
	printLinked(Head);
	printf("delete %d\n", 2);
	deleteNode(Head, 2);
	printLinked(Head);
	printf("delete %d\n", 4);
	deleteNode(Head, 4);
	printLinked(Head);
	return 0;
}
