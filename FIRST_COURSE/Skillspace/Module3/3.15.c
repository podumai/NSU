#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int check_n(char* str) {
	for (int i = 0; i < strlen(str) - 1; i++)
		for (int j = i + 1; j < strlen(str); j++)
			if (str[i] == str[j])
				return 1;

	return 0;
}

int cows(char* str1, char* str2) {
	int count = 0;

	for (int i = 0; i < strlen(str1); i++)
		for (int j = 0; j < strlen(str1); j++)
			if (str1[i] == str2[j] && i != j)
				count++;

	return count;
}

int bulls(char* str1, char* str2) {
	int count = 0;

	for (int i = 0; i < strlen(str1); i++)
		for (int j = 0; j < strlen(str1); j++)
			if (str1[i] == str2[j] && i == j)
				count++;

	return count;
}

int main() {
	char str[5];

	printf("Presenter made a number to guess:\n");

	do {
		scanf("%s", &str);
	} while (check_n(str) == 1);

	for (int i = 0; i < 25; i++)
		printf("\n");
	printf("Player is trying to guess the number:\n");

	int k = 0;

	for (k = 0; k < 10; k++) {
		char str_guess[8];

		do {
			scanf("%s", &str_guess);
		} while (check_n(str_guess) == 1);

		if (bulls(str, str_guess) == strlen(str)) {
			printf("Bulls : %d  Cows: %d\nWin!", bulls(str, str_guess),
				cows(str, str_guess));
			k = 11;
		}
		else
			printf("Bulls : %d  Cows: %d\n", bulls(str, str_guess),
				cows(str, str_guess));
	}

	if (k == 10) {
		printf("Loss!");
	}

	return 0;
}