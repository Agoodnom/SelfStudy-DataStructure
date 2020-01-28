#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data) {
	arr[count] = data;
	count++;
}//값을 뒤에 추가

void addFirst(int data) {
	for (int i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}//값을 앞에 추가

void removeAt(int index) {
	for (int i = index; i < count-1; i++) {
		arr[i] = arr[i+1];
	}
	count--;
}//원하는 인덱스를 삭제

void show() {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}//출력

int main() {
	addBack(8);
	addBack(7);
	addBack(6);
	addFirst(3);
	addFirst(2);
	addFirst(1);
	show();
	system("pause");

	return 0;

}