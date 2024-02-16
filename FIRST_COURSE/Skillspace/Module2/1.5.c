#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


void scanArr(float* arrDots, int lenArr) {
	for (int i = 0; i < lenArr; i++)
		scanf_s("%f", (arrDots + i));
}


float squareHeron(float side1, float side2, float side3) {
	float p = (side1 + side2 + side3) / 2;
	return (sqrt(p * (p - side1) * (p - side2) * (p - side3)));
}


float side(float x1, float y1, float x2, float y2) {
	return (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}


void square(float* arrDots, int lenArr) {
	if (lenArr > 5 && !(lenArr % 2)) {
		float * arrSquares = (float*)malloc((lenArr / 2) * sizeof(float));
		float sum = 0;
		int k = 0;
		for (int i = 2; i < lenArr - 2; i += 2) {
			float side1 = side(*(arrDots), *(arrDots + 1), *(arrDots + i), *(arrDots + i + 1));
			float side2 = side(*(arrDots), *(arrDots + 1), *(arrDots + i + 2), *(arrDots + i + 3));
			float side3 = side(*(arrDots + i), *(arrDots + i + 1), *(arrDots + i + 2), *(arrDots + i + 3));
			*(arrSquares + k) = squareHeron(side1, side2, side3);
			k++;
		}
		for (int i = 0; i < k; i++)
			sum += *(arrSquares + i);
		printf("%f", sum);
		free(arrSquares);
	}
	else
		printf("Bad input");
	free(arrDots);
}


int main() {
	int lenArr;

	scanf_s("%d", &lenArr);

	lenArr *= 2;
	float* arrDots = (float*)malloc(lenArr * sizeof(float));

	scanArr(arrDots, lenArr);
	square(arrDots, lenArr);

	return 0;
}