#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");

	int a, b, c, d, S, s;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	S = a * b;
	s = c * d;

	if (S / s == (b / c * (a / d)))
		printf("������� ���-�� ��������� ���������������, ����������� ������� �������� c,\
����� ���������� ����� �������� ������� b");
	else if (S / s == (a / c * (b / d)))
		printf("������� ���-�� ��������� ���������������, ����������� ������� �������� c,\
����� ���������� ����� ������� ������� a");

	return 0;
}