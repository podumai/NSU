#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int h, m, res;

	scanf("%d%d", &h, &m);

	res = abs(h % 12 * 5 + 15 - m);
	res = (m + res) / 60 * 5 + res;

	printf("%d", res);

	return 0;
}