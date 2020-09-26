// TreeNode.h
#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode();
	TreeNode(int);
	TreeNode(int, TreeNode*, TreeNode*);
};

typedef TreeNode* TreeNodePtr;
#endif