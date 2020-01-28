#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char data[100];
	struct Node *next;
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void push(Stack *stack, char *data) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char* getTop(Stack *stack) {
	Node *top = stack->top;
	return top->data;
}

char* pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("언더플로우가 발생했습니다.\n");
		return NULL;
	}
	Node *node = stack->top;
	char *data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return data;
}

int getPriority(char *i) {
	if (!strcmp(i, "(")) return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}//우선순위 정해주기

char* transition(Stack *stack, char **s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			push(stack, s[i]);
		}//사칙연산기호 일때 stack에 무언가 존재하고 그것의 우선순위가 s[i] 보다 높다면 그것을 꺼내서 res에 넣는다 그리고 s[i]는 stack으로 넣는다
		else if (!strcmp(s[i], "(")) push(stack, s[i]);//"(" 기호가 나오면 stack에 넣는다.
		else if (!strcmp(s[i], ")")) {
			while (strcmp(getTop(stack), "(")) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			pop(stack);
		}//")"기호가 나오면 stack에서 "(" 기호가 나올때까지 차례대로 꺼내서 res에 넣는다 그리고 "("가 나오면 "("기호는 res에 넣지 않고 그냥 pop시킨다.
		else { strcat(res, s[i]); strcat(res, " "); }//숫자가 나오면 바로 res에 넣는다.
	}
	while (stack->top != NULL) {
		strcat(res, pop(stack)); strcat(res, " ");
	}//위에 과정이 끝나고 stack에 남은 연산자들을 모조리꺼내어 res에 넣어준다.
	return res;//후위 표기법으로 변환된 결과를 return해준다.
}//중위 표기법을 후위 표기법으로 변환하는 과정 (중위표기법은 일상적으로 사용하는 표기법이고ex7+6*3 후위표기법은 컴퓨터가 이해하기 쉽게만든 표기법이다ex763*+)

void calculate(Stack *stack, char **s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));
			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
		}//연산자를 만난경우 앞에 숫자 두개를 stack에서 꺼내어 연산한다.그리고 그 결과를 다시 stack에 넣어준다.(순서 주의! y가 먼저 들어가있던 숫자)
		else {
			push(stack, s[i]);
		}//숫자는 바로 stack에 넣어준다.
	}
	printf("%s\n",pop(stack));//마지막에 남은 숫자가 결과이므로 출력.
}

int main() {
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') size++;
	}
	char **input = (char**)malloc(sizeof(char*)*size);
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	
	char *ptr = strtok(a, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}/*strtok을 사용해서 분리된 문자열을 input[i]에 넣는과정.
	strtok는 실행이 끝나면 방금전에 분리한 문자열의 분리지점 바로 다음 주소값을 기억한다.
	따라서 strtok에 NULL값이 들어가면 이전에 자기가 기억한 곳으로부터 분리를 시도한다.*/
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("후위 표기법: %s\n", b);

	size = 1;
	for (int i = 0; i < strlen(b)-1; i++) {//transition함수에 의해서 마지막은 항상 공백이 들어가므로 1을 빼기
		if (b[i] == ' ') size++;
	}

	char *ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}

	calculate(&stack, input, size);
	system("pause");
	return 0;
}