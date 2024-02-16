#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int y;

	scanf("%d", &y);
	printf("%d %d %d", y % 30 * 12, y / 30, y % 30 * 2);

	return 0;
}