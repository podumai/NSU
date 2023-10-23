#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

short int min(short int a, short int b) {
	if (a > b) {
		return b;
	}
	else
		return a;
}

int main() {
	char str[80];
	short int count = 0, res = 100;

	fgets(str, sizeof(str), stdin);

	for (short int i = 0; i != strlen(str); i++) {
		count++;
		if (str[i] == 32 || i == strlen(str) - 1) {
			res = min(res, count - 1);
			count = 0;
		}
	}

	printf("%d", res);

	return 0;
}