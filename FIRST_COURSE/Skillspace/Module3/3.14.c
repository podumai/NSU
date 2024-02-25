#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int match_s(char* str1, char* str2, char* str3) {
	int f = 0;

	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2) {
			str3[i] = &str2;
			f = 1;
		}
	}

	if (f == 1)
		return 1;

	return 0;
}

int main() {
	char riddle[2][20];

	printf("Player is trying to guess the hidden word:\n");

	for (int i = 0; i < 2; i++) {
		fgets(riddle[i], sizeof(riddle[i]), stdin);
		riddle[i][strcspn(riddle[i], "\n")] = 0;
	}

	for (int i = 0; i < 25; i++)
		printf("\n");

	int attempt = 10;
	char s[2], sym[20];
	char word[20] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' , '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*' };

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < strlen(riddle[1]); j++)
			printf("%c", word[j]);

		int choice;

		printf("\nLetter or word (0 - letter, 1 - word)?");
		scanf("%d", &choice);

		if (choice == 0) {
			scanf("%s", &s);
			
			for (int j = 0; j <= strlen(riddle[1]); j++) {
				if (riddle[1][j] == s[0])
					word[j] = s[0];
			}
		}
		else if (choice == 1) {
			scanf("%s", &sym);
			if (strcmp(riddle[1], sym) == 0) {
				printf("Win!");
				i = 10;
			}
			else {
				printf("Loss!");
				i = 10;
			}
		}
	}

	return 0;
}