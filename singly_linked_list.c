#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}//�տ� �߰�(root�� head�� �ش�)

void addBack(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node *cur = root->next;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = node;
}//�ڿ� �߰�

void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}//�տ��� ����

void removeBack(Node *root) {
	Node *cur1 = root->next;
	Node *cur2 = cur1->next;
	while (cur2->next != NULL) {
		cur1 = cur1->next;
		cur2 = cur1->next;
	}
	free(cur2);
	cur1->next = NULL;
}//�ڿ��� ����

void freeAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}//head�� ������ ��� ����Ʈ�� ����

void showAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}//���

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addFront(head, 5);
	addFront(head, 4);
	addFront(head, 3);
	addFront(head, 2);
	addFront(head, 1);
	addLast(head, 6);
	addLast(head, 7);
	addLast(head, 8);
	removeFront(head);
	removeLast(head);
	removeLast(head);
	showAll(head);
	freeAll(head);
	free(head);
	system("pause");
	return 0;
}