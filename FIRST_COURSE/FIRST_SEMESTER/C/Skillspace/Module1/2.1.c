#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");

	int k;

	scanf("%d", &k);

	if (k >= 11 && k <= 14)
            printf("Мы нашли %d грибов в лесу", k);
        else if (k % 10 >= 5 && k % 10 <= 9)
            printf("Мы нашли %d грибов в лесу", k);
        else if (k % 10 >= 2 && k % 10 <= 4)
            printf("Мы нашли %d гриба в лесу", k);
        else
            printf("Мы нашли %d гриб в лесу", k);

	return 0;
}