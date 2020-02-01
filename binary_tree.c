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
}/*전위 순회
 1)루트 노드부터 시작해서 아래로 내려 오면서
 2)왼쪽 하위 트리를 방문하고 왼쪽 하위 트리의 방문이 끝나면
 3)오른쪽 하위 트리를 방문하는 방식*/

void inorder(Node* root) {
	if (root == NULL)
		return;
	inorder(root->leftChild);
	printf("%d ", root->data);
	inorder(root->rightChild);
}
/*중위 순회
1)왼쪽 하위 트리부터 시작해서
2)루트를 거쳐
3)오른쪽 하위 트리를 방문*/

void postorder(Node* root) {
	if (root == NULL)
		return;
	postorder(root->leftChild);
	postorder(root->rightChild);
	printf("%d ", root->data);
}
/*후위 순회법
-전위 순회의 반대
1)왼쪽 하위 트리부터 시작해서
2)오른쪽 형제 노드를 방문 후
3)루트 노드를 방문하는 방법*/

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