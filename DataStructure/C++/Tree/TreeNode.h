/* TreeNode.h */
#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
private:
	int val;
	TreeNode* left, right;

public:
	TreeNode(int val);
}

typedef TreeNode * TreeNodePtr;

#endif