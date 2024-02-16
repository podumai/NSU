#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void scanArr(int* arr, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		scanf_s("%d", (arr + i));
}


void checkSymmetry(int* arr, int lenArr, int leftBord, int rightBord) {
	if (rightBord < lenArr && leftBord >= 0) {
		if (arr[leftBord] == arr[rightBord] && leftBord < rightBord) {
			leftBord++;
			rightBord--;
			checkSymmetry(arr, lenArr, leftBord, rightBord);
		}
		else if (leftBord - 1 == rightBord || leftBord == rightBord)
			printf("This part of array is symmetrical");
		else
			printf("This part of array is not symmetrical");
	}
	else
		printf("Bad input");
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	int* arr = (int*)malloc(lenArr * sizeof(int));
	int i, j;

	scanArr(arr, lenArr);
	scanf_s("%d%d", &i, &j);
	checkSymmetry(arr, lenArr, i, j);
	free(arr);

	return 0;
}