#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	int res1 = (a / b) * (a % b);
	int res2 = (b / a) * (b % a);

	printf("%d", res1 + res2 + 1);

	return 0;
}