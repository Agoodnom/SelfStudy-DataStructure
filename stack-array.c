#include<stdio.h>

#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("스택 오버플러우가 발생했습니다.\n");
		return;
	}
	stack[++top] = data;
}

void pop() {
	if (top == -1) {
		printf("스택 언더플러우가 발생했습니다.\n");
		return;
	}
	stack[top--];
}

void show() {
	printf("--- 스택의 최상단 ---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--- 스택의 최하단 ---\n");
}

int main() {
	push(7);
	push(6);
	push(5);
	push(4);
	pop();
	show();
	system("pause");
	return 0;
}