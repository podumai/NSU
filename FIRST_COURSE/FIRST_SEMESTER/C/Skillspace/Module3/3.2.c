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
	int check[95] = { 0 };

	fgets(str, sizeof(str), stdin);

	for (int i = 0; i < 95; i++)
		for (int j = 0; j <= strlen(str); j++)
			if (str[j] - 32 == i)
				check[i]++;

	int res = 0;

	for (int i = 0; i < 94; i++) {
		if (check[i] < check[i + 1])
			res = max(res, check[i + 1]);
		else
			res = max(res, check[i]);
	}

	printf("%d", res);

	return 0;
}