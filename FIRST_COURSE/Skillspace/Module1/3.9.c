#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	double p = 2.;
	int h = 1;

	while (p > 1) {
		p = 1.29 / pow(2.71828, h * 0.000125);
		h += 1;
	}

	printf("%d", h);

	return 0;
}