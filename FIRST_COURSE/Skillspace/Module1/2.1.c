#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");

	int k;

	scanf("%d", &k);

	if (k >= 11 && k <= 14)
            printf("�� ����� %d ������ � ����", k);
        else if (k % 10 >= 5 && k % 10 <= 9)
            printf("�� ����� %d ������ � ����", k);
        else if (k % 10 >= 2 && k % 10 <= 4)
            printf("�� ����� %d ����� � ����", k);
        else
            printf("�� ����� %d ���� � ����", k);

	return 0;
}