#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void printRandArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++) {
		*(arr + i) = rand();
		printf("%d ", *(arr + i));
	}
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	int* arr = (int*)malloc(lenArr * sizeof(int));

	printRandArr(arr, lenArr);
	free(arr);

	return 0;
}