#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

TreeNodePtr InsertNode_Ascending(TreeNodePtr root, Data item) {
	if (root) {
		// if data of root is smaller than data of item
		if (CompareData(root->data, item) > 0)
			root->left = InsertNode_Ascending(root->left, item);
		// if data of root is bigger than data of item
		else if (CompareData(root->data, item) < 0)
			root->right = InsertNode_Ascending(root->right, item);
	} else root = CreateNode(item);

	return root;
}

TreeNodePtr InsertNode_Descending(TreeNodePtr root, Data item) {
	if (root) {
		// if data of root is bigger than data of item
		if (CompareData(root->data, item) < 0)
			root->left = InsertNode_Descending(root->left, item);
		// if data of root is smaller than data of item
		else if (CompareData(root->data, item) > 0)
			root->right = InsertNode_Descending(root->right, item);
	} else root = CreateNode(item);

	return root;
}

TreeNodePtr InsertTreeNode_Iterator(TreeNodePtr root, Data item) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	if (! root) root = newNode;
	else {
		TreeNodePtr curr = root;
		while (1) {
			// if data of newNode is smaller than data of curr
			if (CompareData(curr->data, newNode->data) > 0) {
				if (! curr->left) {
					curr->left = newNode;
					break;
				}
				else
					curr = curr->left;
			}
			else {
				if (! curr ->right) {
					curr->right = newNode;
					break;
				}
				else
					curr = curr->right;
			}
		}
	}

	return root;
}

// Leftmost node
TreeNodePtr MinValueRight(TreeNodePtr root) {
	TreeNodePtr temp = root;
	while (temp->left)
		temp = temp->left;

	return temp;
}

TreeNodePtr DeleteNode(TreeNodePtr root, Data item) {
	if (! root) return NULL;
	else {
		if (CompareData(root->data, item) > 0)
			root->left = DeleteNode(root->left, item);
		else if (CompareData(root->data, item) < 0)
			root->right = DeleteNode(root->right, item);
		else {
			if (! root->left) {
				TreeNodePtr removed = root;
				root = root->right;
				free(removed);

				return root;
			} else if (! root->right) {
				TreeNodePtr removed = root;
				root = root->left;
				free(removed);

				return root;
			} else {
				TreeNodePtr change = MinValueRight(root->right);
				root->data = change->data;

				root->right = DeleteNode(root->right, change->data);

				return root;
			}
		}
	}
}

TreeNodePtr Search_Recursion(TreeNodePtr root, Data item) {
	if (! root) return NULL;

	if (! CompareData(root->data, item))
		return root;
	else if (CompareData(root->data, item) > 0)
		return Search_Recursion(root->left, item);
	else
		return Search_Recursion(root->right, item);
}

TreeNodePtr Search_Iterator(TreeNodePtr root, Data item) {
	TreeNodePtr node = root;
	while (node) {
		if (! CompareData(node->data, item))
			break;
		else if (CompareData(node->data ,item) > 0)
			node = node->left;
		else
			node = node->right;
	}

	return node;
}
