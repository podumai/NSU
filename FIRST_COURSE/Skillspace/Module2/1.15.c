#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int maxDischargeArr(int* arr, int lenArr) {
	int max = 0, k = 0;
	for (int i = 0; i < lenArr; i++)
		for (int j = 0; j < lenArr; j++)
			if (max < *(arr + i*lenArr + j))
				max = *(arr + i*lenArr + j);
	while (max) {
		max /= 10;
		k += 1;
	}
	return (k + 1);
}


void fillNumsArr(int* arr, int lenArr) {
	int i = 0, counter = 0, k = -1;
	while (counter < lenArr * lenArr) {
		while (k < lenArr - 1 && !*(arr + i*lenArr + (k + 1))) {
			k++;
			*(arr + i*lenArr + k) = ++counter;
		}
		while (i < lenArr - 1 && !*(arr + (i + 1)*lenArr + k)) {
			i++;
			*(arr + i*lenArr + k) = ++counter;
		}
		while (k > 0 && !*(arr + i*lenArr + (k - 1))) {
			k--;
			*(arr + i*lenArr + k) = ++counter;
		}
		while (i > 0 && !*(arr + (i - 1)*lenArr + k)) {
			i--;
			*(arr + i*lenArr + k) = ++counter;
		}
	}
}


void printArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		for (int j = 0; j < lenArr; j++) {
			if (j != lenArr - 1)
				printf("|% *d |", maxDischargeArr(arr, lenArr), *(arr + i*lenArr + j));
			else
				printf("|% *d |\n", maxDischargeArr(arr, lenArr), *(arr + i*lenArr + j));
		}
}

void fillArr(int* arr, int lenArr) {
	if (lenArr > 1) {
		fillNumsArr(arr, lenArr);
		printArr(arr, lenArr);
	}
	else if (lenArr == 1)
		printf("| 1 |\n");
	else
		printf("Bad input\n");
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	int* arr = (int*)calloc(lenArr*lenArr, sizeof(int));

	fillArr(arr, lenArr);
	free(arr);

	return 0;
}