#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 30
#define FALSE 10000

typedef struct Stack {
	char arr[Max_Size];
	int top;
	int count;
}Stack;

int num = 1;
int v = 1;

void StackInit(Stack *sp) {
	sp->top = -1;
	sp->count = 0;
}

void StackJudge(char a, Stack* sp) {
	int x = 0;
	if (a == '(') {
		sp->arr[++sp->top] = '(';
		num *= 2;
		v = 1;
	}
	else if (a == '[') {
		sp->arr[++sp->top] = '[';
		num *= 3;
		v = 1;
	}

	else if (a == ')') {
		if (sp->arr[sp->top] != '(') {
			num = FALSE;
			return;
		}
		if (v == 1) {
			sp->count += num;
			v = 0;
			num /= 2;
		}
		else
			num /= 2;

		sp->top--;
	}
	else if (a == ']') {
		if (sp->arr[sp->top] != '[') {
			num = FALSE;
			return;
		}
		if (v == 1) {
			sp->count += num;
			v = 0;
			num /= 3;
		}
		else
			num /= 3;

		sp->top--;
	}
}

int main() {
	Stack stack;
	StackInit(&stack);
	char input[Max_Size];
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++) {
		StackJudge(input[i], &stack);
		if (num == FALSE) {
			stack.count = 0;
			break;
		}
	}
	if (stack.top != -1)
		stack.count = 0;
	printf("%d", stack.count);
}
