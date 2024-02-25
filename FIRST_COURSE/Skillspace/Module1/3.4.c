#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int k = 50;
	double res = 0.;

	while (k != 0) {
		res = sqrt(res + k);
		k--;
	}

	printf("%.19lf", res);

	return 0;
}