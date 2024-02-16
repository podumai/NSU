#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

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

	for (int j1 = 0; j1 < i; j1++)
		for (int j2 = j1 + 1; j2 < i; j2++)
			if (strcmp(word[j1], word[j2]) == 0)
				printf("%s", word[j1]);

	return 0;
}