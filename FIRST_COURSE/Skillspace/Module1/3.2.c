#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i < 5; i++)
		printf("%d", n % (int)pow(10, i) / (int)pow(10, i - 1));

	printf("%d", n / 10000);

	return 0;
}