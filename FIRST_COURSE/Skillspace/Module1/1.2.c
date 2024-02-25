#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	double n1, n2;

	scanf("%lf %lf", &n1, &n2);

	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;

	printf("%lf  %lf", n1, n2);

	return 0;
}