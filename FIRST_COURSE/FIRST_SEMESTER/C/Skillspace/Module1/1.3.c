#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(){
	int a1, a2, a3, b1, b2;

	scanf("%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2);
	printf("%d%d%d", a1 + (a2 + b1 + (a3 + b2) / 10) / 10,
		(a2 + b1 + (a3 + b2) / 10) % 10, (a3 + b2) % 10);

	return 0;
}