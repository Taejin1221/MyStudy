#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

TreeNodePtr InsertNode_Ascending(TreeNodePtr root, Data item);
TreeNodePtr InsertNode_Descending(TreeNodePtr root, Data item);
TreeNodePtr MinValueRight(TreeNodePtr root);
TreeNodePtr DeleteNode(TreeNodePtr root, Data item);
TreeNodePtr Search_Recursion(TreeNodePtr root, Data item);
TreeNodePtr Search_Iterator(TreeNodePtr root, Data item);

#endif
