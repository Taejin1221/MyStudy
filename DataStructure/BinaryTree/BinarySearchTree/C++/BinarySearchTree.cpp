// BinarySearchTree.cpp
#include <iostream>
#include <queue>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

void BinarySearchTree::InsertNode(int val) {
	TreeNodePtr newNode = new TreeNode(val, nullptr, nullptr);
	root = InsertNode(root, newNode);
}

TreeNodePtr BinarySearchTree::InsertNode(TreeNodePtr root, TreeNodePtr newNode) {
	if (!root)
		return newNode;
	else {
		if (root->val < newNode->val)
			root->right = InsertNode(root->right, newNode);
		else
			root->left = InsertNode(root->left, newNode);

		return root;
	}
}

void BinarySearchTree::Print() {
	this->InorderPrint(root);
}

void BinarySearchTree::InorderPrint(TreeNodePtr root) {
	if (root) {
		this->InorderPrint(root->left);
		std::cout << root->val << ' ' << std::endl;
		this->InorderPrint(root->right);
	}
}