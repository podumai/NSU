#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int keywords(char *str) {
	char *keys[] = { "and", "as", "assert", "break", "class", "continue", "def",
		"del", "elif", "else", "except", "False", "finally", "for", "from", "global",
		"if", "import", "in", "is", "lambda", "None", "nonlocal", "nonlocal", "not",
		"or", "pass", "raise", "return", "True", "try", "while", "with", "yield" };

	for (int i = 0; i < 35; i++) {
		int k = 0;
		if (strlen(str) == strlen(keys[i])) {
			for (int j = 0; j < strlen(str); j++)
				if (str[j] == keys[i][j])
					k++;
			if (k == strlen(str))
				return 0;
			else
				return 1;
		}
	}
}

int grammar(char *str) {
	if ((str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'A' && str[0] <= 'Z') ||
		str[0] == '_')
		for (int i = 0; i < strlen(str); i++)
			if (str[i] >= ':' && str[i] <= '@' || str[i] >= '!' && str[i] <= '/')
				return 0;

	return 1;
}

int main() {
	char str[20];

	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;

	if (grammar(str) && keywords(str))
		printf("Can be a name in Python");
	else
		printf("Can't be a name in Python");

	return 0;
}