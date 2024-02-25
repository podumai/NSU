#define _CRT_SECURE_NO_WARNINGS
#define SHIFT 100000


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void checkDischarge(int* arr, int index1, int index2) {
	if (*(arr + index1) > 9) {
		*(arr + index2) += *(arr + index1) / 10;
		*(arr + index1) %= 10;
	}
}


void permutation(int* arr, int lenArr) {
	arr = (int*)realloc(arr, lenArr * sizeof(int));
	if (arr == NULL)
		exit(0);
	int i = 0, j = 0;
	while (i < SHIFT - 1) {
		*(arr + lenArr - j) = *(arr + i);
		*(arr + i) = 0;
		i++;
		j++;
	}
}


void printArr(int* arr, int lenArr) {
	FILE* file_out = fopen("out.txt", "w");
	int i = 0, k = 1;
	while (!(*(arr + i))) {
		i++;
	}
	for (int j = i; j < lenArr; j++) {
		if (!(k % 215))
			fprintf(file_out, "%d\n", *(arr + j));
		else
			fprintf(file_out, "%d", *(arr + j));
		k++;
	}
	fclose(file_out);
}


void factorial(int num) {
	if (num > 0) {
		int lenArr = 470000;
		int* arr = (int*)calloc(lenArr, sizeof(int));
		*(arr + lenArr - 1) = 1;
		for (int i = 2; i <= num; i++) {
			for (int j = lenArr - 1; j >= 0; j--)
				*(arr + j) *= i;
			for (int k = lenArr - 1; k > 0; k--)
				checkDischarge(arr, k, k - 1);
			if (*arr) {
				lenArr += SHIFT;
				permutation(arr, lenArr);
			}
		}
		printArr(arr, lenArr);
		free(arr);
	}
	else if (!num)
		printf("1");
	else
		printf("Bad input");
}


int main() {
	int num;

	scanf_s("%d", &num);
	factorial(num);

	return 0;
}