#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void scanArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		scanf_s("%d", (arr + i));
}


int maxNum(int** num1, int ** num2) {
	if (num1 > num2)
		return num1;
	return num2;
}


int maxNumArr(int* arr, int lenArr, int max) {
	if (lenArr) {
		max = maxNum(arr[lenArr], max);
		maxNumArr(arr, lenArr - 1, max);
	}
	else if (!lenArr) {
		max = maxNum(arr[lenArr], max);
		return max;
	}
}


int main() {
	int lenArr, max = 0;

	scanf_s("%d", &lenArr);

	int* arr = (int*)malloc(lenArr * sizeof(int));

	scanArr(arr, lenArr);
	printf("%d", maxNumArr(arr, lenArr - 1, max));
	free(arr);

	return 0;
}