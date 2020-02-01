#include<stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];//heap을 이용한 우선운위 큐
	int count;
} priorityQueue;

void push(priorityQueue *pq, int data) {
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}//가장나중에 들어온 값을 부모값과 비교해가며 상향식으로 올려보낸다.
	pq->count++;
}

int pop(priorityQueue *pq) {
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
		if (target == now) break;// 더 이상 내려가지 않아도 될 때 종료
		else {
			swap(&pq->heap[now],&pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 1;
		}
	}
	return res;
}

int main() {
	int n, data;
	scanf("%d", &n);
	priorityQueue pq;
	pq.count = 0;//heap의 루트를 0으로 설정(1로 설정하면 계산이 더 편함)
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);
	}
	printf("\n");

	system("pause");
	return 0;
}