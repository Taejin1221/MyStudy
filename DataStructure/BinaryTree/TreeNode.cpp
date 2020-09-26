// TreeNode.cpp
#include "TreeNode.h"

TreeNode::TreeNode() {
	val = 0;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::TreeNode(int val) {
	this->val = val;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) {
	this->val = val;
	this->left = left;
	this->right = right;
}