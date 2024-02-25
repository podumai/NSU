#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

long long int factorial(long long int a) {
	if (a <= 1)
		return 1;
	else
		return a * factorial(a - 1);
}

int main() {
	int x;
	double res = 0.;
	long long int n;

	scanf("%d%lli", &x, &n);

	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0) {
			res = res + (pow(x, i) / factorial(n, i));
		}
		else {
			res = res - (pow(x, i) / factorial(n, i));
		}
	}

	printf("%lf", res);

	return 0;
}