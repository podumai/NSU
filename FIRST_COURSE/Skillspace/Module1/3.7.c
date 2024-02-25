#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double equation(double a) {
	return (pow(a, 4) + 2 * pow(a, 3) - a - 1);
}

int main() {
	int a = 0, b = 1;
	double dx, mid;

	while (b - a > 0.00001) {
		dx = (b - a) / 2.;
		mid = a + dx;
		if (equation(a) != equation(mid))
			b = mid;
		else
			a = mid;
	}

	printf("%.1lf", mid);

	return 0;
}