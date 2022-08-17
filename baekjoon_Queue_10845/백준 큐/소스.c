#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 10000

typedef struct queue {
	int arr[MAX_SIZE];
	int front;
	int rear;
}queue;

void QueueInit(queue* qp) {
	qp->front = -1;
	qp->rear = -1;
}

int QueueFull(queue* qp) {
	if (qp -> rear == MAX_SIZE-1)
		return TRUE;
	else
		return FALSE;
}

int QueueEmpty(queue* qp) {
	if (qp->front == qp -> rear)
		return TRUE;
	else
		return FALSE;
}
void push(queue* qp, int num) {
	if (QueueFull(qp) == TRUE)
		return;
	else {
		qp->arr[++qp->rear] = num;
	}
}
void pop(queue* qp) {
	if (QueueEmpty(qp) == TRUE)
		printf("-1\n");
	else
		printf("%d\n", qp->arr[++qp->front]);
}
void size(queue* qp) {
	printf("%d\n", qp-> rear - qp ->front);
}

void empty(queue* qp) {
	printf("%d\n", QueueEmpty(qp));
}

void front(queue* qp) {
	if (QueueEmpty(qp) == TRUE)
		printf("-1\n");
	else
		printf("%d\n", qp->arr[qp->front+1]);
}

void back(queue* qp) {
	if (QueueEmpty(qp) == TRUE)
		printf("%d\n", -1);
	else
		printf("%d\n", qp->arr[qp -> rear]);
}

int main()
{
	queue Queue;
	int count;
	scanf("%d", &count);
	QueueInit(&Queue);

	while (count--) {
		char input[10];
		scanf("%s", input);
		if (strcmp(input, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(&Queue, num);
		}
		else if (strcmp(input, "pop") == 0) {
			pop(&Queue);
		}
		else if (strcmp(input, "size") == 0) {
			size(&Queue);
		}
		else if (strcmp(input, "empty") == 0) {
			empty(&Queue);
		}
		else if (strcmp(input, "front") == 0) {
			front(&Queue);
		}
		else if (strcmp(input, "back") == 0) {
			back(&Queue);
		}

	}
}