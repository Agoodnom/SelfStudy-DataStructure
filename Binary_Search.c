#include<stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search(int start, int end, int target) {
	if (start > end) return -9999;
	int mid = (start + end) / 2;
	if (a[mid] == target) return mid;
	else if (a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}//a[mid]가 target보다작으면 왼쪽을 다시 탐색, 아니면 오른쪽을 탐색

int main() {
	int n, target;
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int result = search(0, n - 1, target);
	if (result != -9999) printf("%d index\n", result+1);
	else printf("Fail\n");
	system("pause");
	return 0;
}