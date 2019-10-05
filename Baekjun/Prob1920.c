// Baekjun 1920
#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
	int data;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode, * TreeNodePtr;

TreeNodePtr CreateNode(int item) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->data = item;
	newNode->left = newNode->right = NULL;

	return newNode;
}

TreeNodePtr InsertNode_Ascending(TreeNodePtr root, int item) {
	if (root) {
		if (root->data > item)
			root->left = InsertNode_Ascending(root->left, item);
		else if (root->data < item)
			root->right = InsertNode_Ascending(root->right, item);
	} else root = CreateNode(item);

	return root;
}

int Search_Iterator(TreeNodePtr root, int item) {
	TreeNodePtr node = root;
	while (node) {
		if (node->data == item)
			break;
		else if (node->data > item)
			node = node->left;
		else
			node = node->right;
	}

	if (node == NULL)
		return 0;
	else 
		return 1;
}

void isIn(TreeNodePtr N, int M, int* arrM) {
	for (int i = 0; i < M; i++) {
		printf("%d\n", Search_Iterator(N, arrM[i]));
	}
}

int main(void) {
	int N, M;

	scanf("%d", &N);
	TreeNodePtr TreeN = NULL;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		TreeN = InsertNode_Ascending(TreeN, temp);
	}

	scanf("%d", &M);
	int* arrM = malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++)
		scanf("%d", &arrM[i]);

	isIn(TreeN, M, arrM);

	return 0;
}
