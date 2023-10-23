#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else
		return b;
}

int main() {
	char str[80];
	int res = 0, count = 0;

	fgets(str, sizeof(str), stdin);

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == 32)
			count++;
		else {
			if (str[i] == 32 && i == strlen(str))
				res = max(res, count);
			else {
				res = max(res, count);
				count = 0;
			}
		}
	}

	printf("%d", res);

	return 0;
}