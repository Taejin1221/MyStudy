// BinarySearchTree.h
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "../../TreeNode.h"

class BinarySearchTree {
public:
	BinarySearchTree();

	void InsertNode(int);
	void Print();

private:
	TreeNodePtr root;

	void InorderPrint(TreeNodePtr);
	TreeNodePtr InsertNode(TreeNodePtr, TreeNodePtr);
};

typedef BinarySearchTree BST, * BSTptr;
#endif