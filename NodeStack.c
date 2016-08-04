#include "NodeStack.h"

/*
Stack.c와 알고리즘은 모두 동일.
Stack.c를 기반으로 BinaryTree의 Node를 담기위한 Stack으로 변경함
변수, 함수 명 등만 수정된 것
*/

void NodeStack_StackInit(NodeStack_Stack* stack) {
	stack->head = NULL;
}
int NodeStack_IsEmpty(NodeStack_Stack* stack) {
	if (stack->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void NodeStack_Push(NodeStack_Stack* stack, NodeStack_Data data) {
	NodeStack_Node* newNode = (NodeStack_Node*)malloc(sizeof(NodeStack_Node));
	newNode->data = data;
	newNode->next = stack->head;

	stack->head = newNode;
}
NodeStack_Data NodeStack_Pop(NodeStack_Stack* stack) {
	NodeStack_Node* delNode;
	Data returnData;

	if (IsEmpty(stack)) {
		exit(-1);
	}

	delNode = stack->head;
	returnData = delNode->data;

	stack->head = stack->head->next;
	free(delNode);

	return returnData;
}
NodeStack_Data NodeStack_Peek(NodeStack_Stack* stack) {
	Data returnData;

	if (IsEmpty(stack)) {
		exit(-1);
	}

	returnData = stack->head->data;

	return returnData;
}