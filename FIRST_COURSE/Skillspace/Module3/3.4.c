#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char str[80];
	int check[95] = { 0 };

	fgets(str, sizeof(str), stdin);

	for (int i = 0; i < 95; i++)
		for (int j = 0; j <= strlen(str); j++)
			if (str[j] - 32 == i)
				check[i]++;

	int res = 0;

	for (int i = 0; i < 95; i++)
		if (check[i] == 3)
			printf("%c", i - 16 + '0');

	return 0;
}