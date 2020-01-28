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
} //������������ ����

void removeFront() {
	Node *node = head->next;
	Node *next = node->next;
	head->next = next;
	next->prev = head;
	free(node);
}//�պκ� ����

void removeBack() {
	Node *node = tail->prev;
	Node *prev = node->prev;
	prev->next = tail;
	tail->prev = prev;
	free(node);
}//�޺κ� ����

void showAll() {
	Node *cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}//���

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
}//�����Ҵ�����

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