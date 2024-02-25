#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int maxDischargeArr(int* arr, int lenArr) {
	int max = 0, k = 0;
	for (int i = 0; i < lenArr; i++)
		if (max < *(arr + i))
			max = *(arr + i);
	while (max) {
		max /= 10;
		k++;
	}
	return  (k + 1);
}


void scanArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		scanf_s("%d", (arr + i));
}


void printArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		if (*(arr + i))
			printf("|% *d |", maxDischargeArr(arr, lenArr), *(arr + i));
}


void eleminateRepetitions(int * arr, int lenArr) {
	for (int i = 0; i < lenArr - 1; i++)
		for (int j = i + 1; j < lenArr; j++)
			if (*(arr + i) == *(arr + j))
				*(arr + j) = 0;
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	int* arr = (int*)calloc(lenArr, sizeof(int));

	scanArr(arr, lenArr);
	eleminateRepetitions(arr, lenArr);
	printArr(arr, lenArr);
	free(arr);

	return 0;
}