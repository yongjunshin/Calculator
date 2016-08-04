#include "BinaryTree.h"
#include "Stack.h"
#include "NodeStack.h"
#include "ExpressionTree.h"

TreeNode* MakeExpTree(char exp[]) {
	NodeStack_Stack ns;
	TreeNode* tree = NULL;
	int postLen = 0;
	char* post;
	int i = 0;
	
	post = InfixToPostfix(exp);
	postLen = strlen(post);
	
	NodeStack_StackInit(&ns);
	for (i = 0; i < postLen; i++) {
		tree = MakeTreeNode();

		if (isdigit(post[i])) {
			SetData(tree, post[i]);
		}
		else {
			SetData(tree, post[i]);
			MakeRightSubTree(tree, NodeStack_Pop(&ns));
			MakeLeftSubTree(tree, NodeStack_Pop(&ns));
		}

		NodeStack_Push(&ns, tree);
	}
	tree = NodeStack_Pop(&ns);

	return tree;
}
double EvaluateExpTree(TreeNode* tree) {
	int left;
	int right;

	if (tree == NULL) {
		return;
	}
	if (isdigit(tree->data)) {
		return tree->data - '0';
	}
	else {
		left = EvaluateExpTree(tree->left);
		right = EvaluateExpTree(tree->right);
		if (tree->data == '+') {
			return left + right;
		}
		else if (tree->data == '-') {
			return left - right;
		}
		else if (tree->data == '*') {
			return left * right;
		}
		else if (tree->data == '/') {
			return (double)left / (double)right;
		}
		else {
			printf("operator error!\n");
			exit(-1);
		}
	}
}

void ShowPrefixTypeExp(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	ShowPrefixTypeExp(tree->left);
	ShowPrefixTypeExp(tree->right);
}
void ShowInfixTypeExp(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	ShowInfixTypeExp(tree->left);
	printf("%c", tree->data);
	ShowInfixTypeExp(tree->right);
}
void ShowPostfixTypeExp(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	ShowPostfixTypeExp(tree->left);
	ShowPostfixTypeExp(tree->right);
	printf("%c", tree->data);
}

int Priority(int a, int b) {
	int aa, bb;

	if (a == '*' || a == '/') {
		aa = 2;
	}
	else if (a == '+' || a == '-') {
		aa = 1;
	}
	else if (a == '(' || a == ')' || a == '{' || a == '}') {
		aa = 0;
	}
	else {
		aa = -1;
	}

	if (b == '*' || b == '/') {
		bb = 2;
	}
	else if (b == '+' || b == '-') {
		bb = 1;
	}
	else if (b == '(' || b == ')' || b == '{' || b == '}') {
		bb = 0;
	}
	else {
		bb = -1;
	}

	if (aa > bb) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

char* InfixToPostfix(char infix[]) {
	Stack s;
	int len = strlen(infix);
	int lenExceptParentheses = 0;
	char* post;
	int i = 0;
	int j = 0;

	for (i = 0; i < len; i++) {
		if (infix[i] != '(' && infix[i] != ')' && infix[i] != '{' && infix[i] != '}') {
			lenExceptParentheses++;
		}
	}
	post = (char*)malloc(sizeof(char)*(lenExceptParentheses+1));

	StackInit(&s);
	for (i = 0; i < len; i++) {
		if (isdigit(infix[i])) {
			post[j++] = infix[i];
		}
		else {
			if (IsEmpty(&s)) {
				Push(&s, infix[i]);
			}
			else {
				if (Priority(infix[i], Peek(&s)) || infix[i] == '(' || infix[i] == '{') {
					Push(&s, infix[i]);
				}
				else {
					while (!IsEmpty(&s) && !Priority(infix[i], Peek(&s))) {
						if (Peek(&s) == '(' || Peek(&s) == '{') {
							Pop(&s);
							break;
						}
						else {
							post[j++] = Pop(&s);
						}
					}
					if (infix[i] != ')' && infix[i]!='}') {
						Push(&s, infix[i]);
					}
				}
			}
		}
	}
	while (!IsEmpty(&s)) {
		post[j++] = Pop(&s);
	}
	post[j] = '\0';

	return post;
}