#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "BinaryTree.h"

TreeNodePtr CreateNode(Data item) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->data = item;
	newNode->left = newNode->right = NULL;

	return newNode;
}

void Preorder(TreeNodePtr root) {
	if (root) {
		PrintData(root->data); printf("->");
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(TreeNodePtr root) {
	if (root) {
		Inorder(root->left);
		PrintData(root->data); printf("->");
		Inorder(root->right);
	}
}

void Postorder(TreeNodePtr root) {
	if (root) {
		Postorder(root->left);
		Postorder(root->right);
		PrintData(root->data); printf("->");
	}	
}

// void Inorder_Iterator(TreeNodePtr root) {

// }

// void LevelTraversal(TreeNodePtr root) {

// }

int GetNodeCount(TreeNodePtr root) {
	if (! root)
		return 0;
	else
		return (1 + GetNodeCount(root->left) + GetNodeCount(root->right));
}

int GetLeafNode(TreeNodePtr root) {
	if (! root) return 0;
	if (!(root->left) && !(root->right))
		return 1;
	else
		return (GetLeafNode(root->left) + GetLeafNode(root->right));
}

int GetHeight(TreeNodePtr root) {
	if (! root)
		return 0;
	else
		return (1 + MAX(GetHeight(root->left), GetHeight(root->right)));
}

bool IsBalanced(TreeNodePtr root) {
	if (! root) return true;
	else {
		if (ABS(GetHeight(root->left) - GetHeight(root->right)) <= 1)
			return (IsBalanced(root->left) && IsBalanced(root->right));
		else
			return false;
	}
}

int GetSum(TreeNodePtr root) {
	if (! root)
		return 0;
	else
		return (root->data.num + GetSum(root->left) + GetSum(root->right));
}

void MinValue(TreeNodePtr root, Data item) {
	if (root) {
		if (CompareData(root->data, item) < 0) {
			PrintData(root->data); puts("");
		}
		MinValue(root->left, item);
		MinValue(root->right, item);
	}
}

int OneChild(TreeNodePtr root) {
	if (! root) 
		return 0;
	else {
		if (! (root->left) && (root->right))
			return (1 + OneChild(root->right));
		else if ((root->left) && ! (root->right))
			return (1 + OneChild(root->left));
		else
			return (OneChild(root->right) + OneChild(root->left));
	}
}

Data Max(TreeNodePtr root) {
	if (root) {
		Data max = root->data;
		return (MaxData(max, MaxData(Max(root->left), Max(root->right))));
	}
	else return CreateData(0);
}

Data Min(TreeNodePtr root) {
	if (root) {
		Data min = root->data;
		return (MinData(min, MinData(Min(root->left), Min(root->right))));
	}
	else return CreateData(INT_MAX);
}

void IncrementNode(TreeNodePtr root) {
	if (root) {
		IncrementData(&(root->data));
		IncrementNode(root->left);
		IncrementNode(root->right);
	}
}

int mystery(TreeNodePtr root) {
	if (root == NULL) return 0;
	else if (root->left == NULL && root->right == NULL)
		return root->data.num;
	else
		return MAX(mystery(root->left), mystery(root->right));
}