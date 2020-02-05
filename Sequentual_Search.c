#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 100

char **array;
int founded=0;

int main() {
	int n;
	char *word;
	word = (char*)malloc(sizeof(char)*LENGTH);
	scanf("%d %s", &n, word);
	array = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++) {
		array[i] = (char*)malloc(sizeof(char)*LENGTH);
		scanf("%s", array[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!strcmp(array[i], word)) {
			printf("%d index.\n", i + 1);
			founded = 1;
		}
	}//단순히 하나씩 비교해가며 확인하는 '순차 탐색'
	if (!founded) {
		printf("Fail\n");
	}
	system("pause");
	return 0;
}