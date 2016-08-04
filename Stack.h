#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0

#define NULL 0

typedef int Data;

typedef struct Node {
	Data data;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* head;
} Stack;

void StackInit(Stack* stack);
int IsEmpty(Stack* stack);

void Push(Stack* stack, Data data);
Data Pop(Stack* stack);
Data Peek(Stack* stack);

#endif