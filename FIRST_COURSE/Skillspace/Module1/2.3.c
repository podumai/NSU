#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");

	int a, b, c, d, S, s;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	S = a * b;
	s = c * d;

	if (S / s == (b / c * (a / d)))
		printf("Большее кол-во картонных прямоугольников, размещенных длинной стороной c,\
можно разместить вдоль короткой стороны b");
	else if (S / s == (a / c * (b / d)))
		printf("Большее кол-во картонных прямоугольников, размещенных длинной стороной c,\
можно разместить вдоль длинной стороны a");

	return 0;
}