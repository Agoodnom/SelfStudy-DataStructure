#include<stdio.h>
#define MAX 10000

void radixSort(int *a, int n) {
	int res[MAX], maxValue = 0;
	int exp = 1;//자릿수
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) {//1의 자리부터 계산
		int bucket[10] = { 0, };
		for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++;//자릿수 배열 처리
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];//누적 계산
		for (int i = n - 1; i >= 0; i--) res[--bucket[a[i] / exp % 10]] = a[i];
		/*a 배열 오른쪽에 들어있는 수부터, exp(자릿수)에 해당하는 숫자를 확인후
		bucket에 저장된 누적된수 -1 에 해당하는 자리(res배열)에 집어넣는다*/
		for (int i = 0; i < n; i++) a[i] = res[i];//기본 배열 갱신
		exp *= 10;
	}
}

int main() {
	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	radixSort(a, n);
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	system("pause");
	return 0;
}