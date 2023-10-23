#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");

	double t;
	
	scanf("%lf", &t);

	t = floor(t) + 1.;

	if ((((int)t + 1) % 5 == 0 || ((int)t + 2) % 5 == 0 || (int)t % 5 == 0)
		&& (int)t != 3)
		printf("Красный");
	else
		printf("Зеленый");

	return 0;
}