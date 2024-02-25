#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	float a, b;

	scanf("%lf", &a);

	b = a;
	a *= a;
	a *= a;
	a *= a;
	a *= a;
	a = a / (b * b);
	a *= a;

	printf("%lf", a);

	return 0;
}