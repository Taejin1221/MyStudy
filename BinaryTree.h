#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include "../Data.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
typedef struct _TreeNode {
	Data data;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode, * TreeNodePtr;


TreeNodePtr CreateNode(Data item);
void Preorder(TreeNodePtr root);
void Inorder(TreeNodePtr root);
void Postorder(TreeNodePtr root);
// void Inorder_Iterator(TreeNodePtr root);
// void LevelTraversal(TreeNodePtr root);
int GetNodeCount(TreeNodePtr root);
int GetLeafNode(TreeNodePtr root);
int GetHeight(TreeNodePtr root);
bool IsBalanced(TreeNodePtr root);
int GetSum(TreeNodePtr root);
void MinValue(TreeNodePtr root, Data item);
int OneChild(TreeNodePtr root);
Data Max(TreeNodePtr root);
Data Min(TreeNodePtr root);
void IncrementNode(TreeNodePtr root);
int mystery(TreeNodePtr root);

#endif