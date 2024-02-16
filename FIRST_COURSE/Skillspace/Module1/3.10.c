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
	int n;
	double res = 0.;

	scanf("%d", &n);
		
	for (int i = 1; i <= n; i++) {
		double f = 1.;
		for (int j = i; j <= 2 * n; j++) {
			f = f * ((pow(-1., i) * (j + 1)) / factorial(j - i + 1));
		}
		res = res + f;
	}

	printf("%lf\n", res);

	return 0;
}