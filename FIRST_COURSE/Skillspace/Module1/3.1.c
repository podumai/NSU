#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int k;

	scanf("%d", &k);

	int diff = k * k - (k - 1) * (k - 1);
	k-=2;

	while (k > 0) {
		diff = diff - k * k - (k - 1) * (k - 1);
		k-=2;
	}

	printf("%d", diff);

	return 0;
}