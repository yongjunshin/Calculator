#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#define NULL 0

typedef int Data;

typedef struct TreeNode {
	Data data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* MakeTreeNode(void);
Data GetData(TreeNode* node);
void SetData(TreeNode* node, Data data);

TreeNode* GetLeftSubTree(TreeNode* tree);
TreeNode* GetRightSubTree(TreeNode* tree);

void MakeLeftSubTree(TreeNode* main, TreeNode* sub);
void MakeRightSubTree(TreeNode* main, TreeNode* sub);

void DeallocNode(TreeNode* node);

#endif