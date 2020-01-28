#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

Node *head, *tail;

void insert(int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;

	Node *cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node *prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	node->next = cur;
	cur->prev = node;
} //오름차순으로 삽입

void removeFront() {
	Node *node = head->next;
	Node *next = node->next;
	head->next = next;
	next->prev = head;
	free(node);
}//앞부분 제거

void removeBack() {
	Node *node = tail->prev;
	Node *prev = node->prev;
	prev->next = tail;
	tail->prev = prev;
	free(node);
}//뒷부분 제거

void showAll() {
	Node *cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}//출력

void freeAll() {
	Node *cur = head->next;
	Node *temp;
	while (cur != tail) {
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	free(head);
	free(tail);
}//동적할당해제

int main() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(3);
	insert(5);
	insert(2);
	insert(6);
	insert(1);
	insert(4);
	insert(1);
	insert(11);
	removeFront();
	removeBack();
	showAll();
	freeAll();
	system("pause");
	return 0;
}