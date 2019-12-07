/* BinarySearchTree.h */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"

class BinarySearchTree {
private:
	TreeNodePtr root;

public:
	BinarySearchTree(int val);
	void InsertNode(int val);
	TreeNodePtr SearchNode(int val);
	bool DeleteNode(int val);
};

typedef BinarySearchTree * BinarySearchTreePtr;

#endif
