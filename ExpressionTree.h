#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__

#define TRUE 1
#define FALSE 0

#include "BinaryTree.h"

TreeNode* MakeExpTree(char exp[]);
double EvaluateExpTree(TreeNode* tree);

void ShowPrefixTypeExp(TreeNode* tree);
void ShowInfixTypeExp(TreeNode* tree);
void ShowPostfixTypeExp(TreeNode* tree);

int Priority(int a, int b);
char* InfixToPostfix(char infix[]);


#endif