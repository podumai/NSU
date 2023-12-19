#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int maxNum(int num1, int num2) {
	if (num1 > num2)
		return num1;
	return num2;
}


void scanArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		scanf_s("%d", (arr + i));
}


void printLenOdd(int* arr, int lenArr) {
	int max = 0, count = 0;
	for (int i = 0; i < lenArr; i++) {
		if (*(arr + i) % 2)
			count++;
		else {
			max = maxNum(max, count);
			count = 0;
		}
	}
	printf("%d", max);
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	int* arr = (int*)malloc(lenArr * sizeof(int));

	scanArr(arr, lenArr);
	printLenOdd(arr, lenArr);
	free(arr);

	return 0;
}