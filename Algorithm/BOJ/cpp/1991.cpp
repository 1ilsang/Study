//https://www.acmicpc.net/problem/1991
//

#include <cstdio>

struct Node {
	char data;
	Node *left, *right;
	Node(char num) {
		data = num;
		left = NULL;
		right = NULL;
	}
};

void createNode(Node * tree, char now, char left, char right) {
	if (tree == NULL) return;
	if (tree->data != now) {
		createNode(tree->left, now, left, right);
		createNode(tree->right, now, left, right);
	}
	else {
		tree->left = new Node(left);
		tree->right = new Node(right);
		return;
	}
}

void printPreorder(Node *tree) {
	if (tree == NULL || tree->data == NULL)return;
	printf("%C", tree->data);
	printPreorder(tree->left);
	printPreorder(tree->right);
}
void printInorder(Node *tree) {
	if (tree == NULL || tree->data == NULL)return;
	printInorder(tree->left);
	printf("%C", tree->data);
	printInorder(tree->right);
}
void printPostorder(Node*tree) {
	if (tree == NULL || tree->data == NULL)return;
	printPostorder(tree->left);
	printPostorder(tree->right);
	printf("%C", tree->data);
}

int main(void) {
	Node *tree = new Node(NULL);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char now, left, right;
		scanf(" %c %c %c", &now, &left, &right);
		if (left == '.') left = NULL;
		if (right == '.') right = NULL;
		if (tree->data == NULL) {
			tree->data = now;
			tree->left = new Node(left);
			tree->right = new Node(right);
		}
		else {
			createNode(tree, now, left, right);
		}
	}
	printPreorder(tree), puts("");
	printInorder(tree), puts("");
	printPostorder(tree), puts("");
	return 0;
}
