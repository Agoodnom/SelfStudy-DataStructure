#include<stdio.h>
#define MAX_VALUE 10001
//입력되는 값중 10000보다 큰값이 들어오면 안된다.

int n, m;
int a[MAX_VALUE];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) {
			printf("%d ", i);
			a[i]--;
		}
	}
	
	system("pause");
	return 0;
}//계수정렬은 데이터의 크기가 한정적일때 사용