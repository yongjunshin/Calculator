#ifndef __NODESTACK_H__
#define __NODESTACK_H__

/*
Stack.h와 알고리즘은 모두 동일.
Stack.h를 기반으로 BinaryTree의 Node를 담기위한 Stack으로 변경함
변수, 함수 명 등만 수정된 것
*/
#define TRUE 1
#define FALSE 0

#define NULL 0

#include "BinaryTree.h"

typedef TreeNode* NodeStack_Data;

typedef struct NodeStack_Node {
	Data data;
	struct NodeStack_Node* next;
} NodeStack_Node;

typedef struct NodeStack_Stack {
	NodeStack_Node* head;
} NodeStack_Stack;

void NodeStack_StackInit(NodeStack_Stack* stack);
int NodeStack_IsEmpty(NodeStack_Stack* stack);

void NodeStack_Push(NodeStack_Stack* stack, NodeStack_Data data);
NodeStack_Data NodeStack_Pop(NodeStack_Stack* stack);
NodeStack_Data NodeStack_Peek(NodeStack_Stack* stack);

#endif