#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int k;

	scanf("%d", &k);
	printf("%d", k/3%10);

	return 0;
}