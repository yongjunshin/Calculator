#include "Stack.h"

void StackInit(Stack* stack) {
	stack->head = NULL;
}
int IsEmpty(Stack* stack) {
	if (stack->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Push(Stack* stack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->head;

	stack->head = newNode;
}
Data Pop(Stack* stack) {
	Node* delNode;
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
Data Peek(Stack* stack) {
	Data returnData;

	if (IsEmpty(stack)) {
		exit(-1);
	}

	returnData = stack->head->data;
	
	return returnData;
}