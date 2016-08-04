#include "BinaryTree.h"

TreeNode* MakeTreeNode(void) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
Data GetData(TreeNode* node) {
	return node->data;
}
void SetData(TreeNode* node, Data data) {
	node->data = data;
}

TreeNode* GetLeftSubTree(TreeNode* tree) {
	return tree->left;
}
TreeNode* GetRightSubTree(TreeNode* tree) {
	return tree->right;
}

void MakeLeftSubTree(TreeNode* main, TreeNode* sub) {
	//free left
	DeallocNode(main->left);

	main->left = sub;
}
void MakeRightSubTree(TreeNode* main, TreeNode* sub) {
	//free right
	DeallocNode(main->right);
	
	main->right = sub;
}

void DeallocNode(TreeNode* node) {
	if (node == NULL) {
		return;
	}

	DeallocNode(node->left);
	DeallocNode(node->right);
	free(node);
}