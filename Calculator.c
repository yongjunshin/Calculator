#include "Calculator.h"
#include "ExpressionTree.h"


double Calculate(char* exp) {
	TreeNode* expressionBinaryTree;

	expressionBinaryTree = MakeExpTree(exp);

	return EvaluateExpTree(expressionBinaryTree);
}