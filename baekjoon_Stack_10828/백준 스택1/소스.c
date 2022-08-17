#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 10000

typedef struct stack {
	int arr[MAX_SIZE];
	int top;
}stack;

void StackInit(stack* sp) {
	sp->top = -1;
}

int StackFull(stack* sp) {
	if (sp->top + 1 >= MAX_SIZE)
		return TRUE;
	return FALSE;
}

int StackEmpty(stack* sp) {
	if (sp->top == -1)
		return TRUE;
	return FALSE;
}
void push(stack *sp,int num) {
	if (StackFull(sp) == TRUE) 
		printf("Stack is full\n");
	else {
		sp->top++;
		sp->arr[sp->top] = num;
	}
}
void pop(stack *sp) {
	if (StackEmpty(sp) == TRUE)
		printf("-1\n");
	else
		printf("%d\n", sp->arr[sp->top--]);
}
void size(stack *sp) {
	printf("%d\n", sp->top+1);
}

void empty(stack *sp) {
	printf("%d\n", StackEmpty(sp));
}

void top(stack *sp) {
	if (StackEmpty(sp) == TRUE)
		printf("%d\n", -1);
	else
		printf("%d\n", sp->arr[sp->top]);
}
int main()
{
	stack Stack;
	int count;
	scanf("%d", &count);
	StackInit(&Stack);

	while (count--) {
		char input[10];
		scanf("%s", input);
		if (strcmp(input, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(&Stack,num);
		}
		else if (strcmp(input, "pop") == 0) {
			pop(&Stack);
		}
		else if (strcmp(input, "size") == 0) {
			size(&Stack);
		}
		else if (strcmp(input, "empty") == 0) {
			empty(&Stack);
		}
		else if (strcmp(input, "top") == 0) {
			top(&Stack);
		}

	}
}