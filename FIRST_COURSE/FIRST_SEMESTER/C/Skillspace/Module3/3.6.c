#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char str[80], res[80];
	short int count = 0, k = 0;

	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;

	for (short int i = strlen(str) - 1; i > -1; i--) {
		count++;
		if (str[i] == 32 || i == 0) {
			for (short int j = 0; j < count; j++) {
				if (str[i + j] != 32 && i != 0) {
					res[k] = str[i + j];
					k++;
				}
				else if (i == 0) {
					res[k] = str[i];
					res[k + 1] = str[i + 1];
				}
				else
					res[k + count - 1] = 32;
			}
			if (res[k] == 32)
				k++;
			count = 0;
		}
	}

	for (short int i = 0; i <= k + 1; i++)
		printf("%c", res[i]);

	return 0;
}