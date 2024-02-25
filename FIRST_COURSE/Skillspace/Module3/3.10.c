#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int match(char* str) {
	char sym[128];

	for (int i = 0; i < 95; i++)
		for (int j = 0; j < strlen(str); j++)
			if (str[j] == i)
				sym[i]++;

	for (int i = 0; i < 128; i++)
		if (sym[i] >= 2)
			return 1;

	return 0;
}

int main() {
	char str[80];
	char* words[80];
	int i = 0;

	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;

	char* word = strtok(str, " ");

	while (word != NULL) {
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}

	for (int j = 1; j < i; j++) {
		if (strcmp(words[0], words[j]) != 0 && match(words[j]) == 0)
			printf("%s ", words[j]);
	}

	return 0;
}