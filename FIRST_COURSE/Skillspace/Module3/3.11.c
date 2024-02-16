#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int match(char* str1, char* str2) {
	if (str1[strlen(str1) - 1] == str2[0] || 
		str1[strlen(str1) - 1] - 32 == str2[0] || 
		str1[strlen(str1) - 1] + 32 == str2[0])
		return 1;
	return 0;
}

int main() {
	int f = 0, count = 0;
	char city_prev[30];
	
	fgets(city_prev, sizeof(city_prev), stdin);
	city_prev[strcspn(city_prev, "\n")] = 0;

	while (f == 0) {
		char city_curr[20];

		fgets(city_curr, sizeof(city_curr), stdin);
		city_curr[strcspn(city_curr, "\n")] = 0;

		if (match(city_prev, city_curr) == 1) {
			strcpy(city_prev, city_curr);
		}
		else {
			if (count % 2 == 0) {
				printf("The winner is Petya");
				f = 1;
			}
			else {
				printf("The winner is Vasya");
				f = 1;
			}
		}

		count++;
	}

	return 0;
}