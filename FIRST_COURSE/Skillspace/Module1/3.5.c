#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	double s = 0., f;

	for (int i = 0; i < 9; i++) {
		f = sin((3.24 / 10) * i);
		s += (3.24 / 10) * f;
	}

	printf("%.5lf", s);

	return 0;
}