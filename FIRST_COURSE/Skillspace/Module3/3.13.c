#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	short int f = 0, sum1 = 0, sum2 = 0, count = 0;

	do {
		char str[30];

		fgets(str, sizeof(str), stdin);

		count++;

		if ((strlen(str) - 1) % 2 == 0) {
			for (short int i = 0; i < strlen(str) - 1; i++) {
				if (i < (strlen(str) - 1) / 2)
					sum1 = sum1 + str[i] - 48;
				else
					sum2 = sum2 + str[i] - 48;
			}
			if (sum1 == sum2) {
				f = 1;
				str[strcspn(str, "\n")] = 0;
				printf("The number of happy ticket is %s", str);
			}
			else {
				sum1 = 0;
				sum2 = 0;
			}
			for (short int i = 0; i < 30; i++)
				str[i] = "";
		}

	} while (f == 0);

	return 0;
}