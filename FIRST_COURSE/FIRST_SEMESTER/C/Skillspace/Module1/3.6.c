#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	double res = 0.;
	int n = 201;

	while (n != 1) {
		res = 1. / (res + n);
		n -= 2;
	}

	printf("%.54lf", res);

	return 0;
}