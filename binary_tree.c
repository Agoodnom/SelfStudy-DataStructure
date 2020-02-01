#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
} Node;

Node* initNode(int data, Node*leftChild, Node*rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
}

void preorder(Node* root) {
	if (root == NULL)
		return;
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
}/*���� ��ȸ
 1)��Ʈ ������ �����ؼ� �Ʒ��� ���� ���鼭
 2)���� ���� Ʈ���� �湮�ϰ� ���� ���� Ʈ���� �湮�� ������
 3)������ ���� Ʈ���� �湮�ϴ� ���*/

void inorder(Node* root) {
	if (root == NULL)
		return;
	inorder(root->leftChild);
	printf("%d ", root->data);
	inorder(root->rightChild);
}
/*���� ��ȸ
1)���� ���� Ʈ������ �����ؼ�
2)��Ʈ�� ����
3)������ ���� Ʈ���� �湮*/

void postorder(Node* root) {
	if (root == NULL)
		return;
	postorder(root->leftChild);
	postorder(root->rightChild);
	printf("%d ", root->data);
}
/*���� ��ȸ��
-���� ��ȸ�� �ݴ�
1)���� ���� Ʈ������ �����ؼ�
2)������ ���� ��带 �湮 ��
3)��Ʈ ��带 �湮�ϴ� ���*/

int main(void) {
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	printf("\n");
	system("pause");
	return 0;
}
/*
					n1(30)
								 
			n2(17)			n3(48)

		n4(05)	n5(23)	n6(37)	n7(50)
*/