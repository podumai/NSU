#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char str[80];
	int i = 0;
	char* words[80];

	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;

	char* word = strtok(str, " ");

	while (word != NULL) {
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}

	int n = i;

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (strlen(words[j]) > strlen(words[j + 1])) {
				char* rep = words[j];
				words[j] = words[j + 1];
				words[j + 1] = rep;
			}

	for (i = 0; i < n; i++)
		printf("%s ", words[i]);

	return 0;
}