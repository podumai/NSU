#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int checkLen(int len1, int len2) {
	if (len1 > len2)
		return len1;
	return len2;
}


void scanArr(int* arr, int lenArr1, int lenArr2) {
	if (lenArr1 > lenArr2)
		for (int i = 0; i < lenArr1; i++)
			scanf_s("%d", (arr + i));
	else if (lenArr1 < lenArr2)
		for (int i = lenArr2 - lenArr1; i < lenArr2; i++)
			scanf_s("%d", (arr + i));
	else
		for (int i = 0; i < lenArr1; i++)
			scanf_s("%d", (arr + i));
}


void printArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		printf("%d", *(arr + i));
}


void calculations(int* arr1, int* arr2, int lenArr) {
	for (int i = lenArr - 1; i >= 0; i--) {
		*(arr1 + i) += *(arr2 + i);
		if (i && *(arr1 + i) > 9) {
			*(arr1 + i - 1) += 1;
			*(arr1 + i) %= 10;
		}
	}
	printArr(arr1, lenArr);
}


int main() {
	int lenArr1, lenArr2;

	scanf_s("%d%d", &lenArr1, &lenArr2);

	int max = checkLen(lenArr1, lenArr2);

	int* arr1 = (int*)calloc(max, sizeof(int));
	int* arr2 = (int*)calloc(max, sizeof(int));

	scanArr(arr1, lenArr1, lenArr2);
	scanArr(arr2, lenArr2, lenArr1);
	calculations(arr1, arr2, max);
	free(arr1);
	free(arr2);

	return 0;
}