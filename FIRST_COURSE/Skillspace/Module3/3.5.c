#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char str[3][20];
	short int check[3][256] = { 0 };

	for (short int i = 0; i < 3; i++) {

		fgets(str[i], sizeof(str[i]), stdin);

		for (short int j = 0; j < strlen(str[i]) - 1; j++)
			check[i][str[i][j]]++;
	}

	for (short int i = 0; i < 3; i++)
		for (short int j = 0; j < 256; j++) {
			if (i == 0) {
				if (check[i][j] != check[i + 1][j] && check[i][j] != check[i + 2][j]
					&& check[i][j]) {
					printf("%c\n", j);
				}
			}
			else if (i == 1) {
				if (check[i][j] != check[i - 1][j] && check[i][j] != check[i + 1][j]
					&& check[i][j]) {
					printf("%c\n", j);
				}
			}
			else if (i == 2) {
				if (check[i][j] != check[i - 1][j] && check[i][j] != check[i - 2][j]
					&& check[i][j]) {
					printf("%c", j);
				}
			}
		}

	return 0;
}