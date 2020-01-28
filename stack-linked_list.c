#include<stdio.h>
#include<stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
}Node;

typedef struct {
	Node *top;
}Stack;

void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

void pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node *node = stack->top;
	stack->top = node->next;
	free(node);
}

void show(Stack *stack) {
	Node *cur = stack->top;
	printf("--- 스택의 최상단 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최상단 ---\n");
}

int main() {
	Stack stack;
	stack.top = NULL;
	push(&stack, 7);
	push(&stack, 6);
	push(&stack, 5);
	push(&stack, 4);
	pop(&stack);
	push(&stack, 3);
	pop(&stack);
	show(&stack);

	system("pause");
	return 0;
}